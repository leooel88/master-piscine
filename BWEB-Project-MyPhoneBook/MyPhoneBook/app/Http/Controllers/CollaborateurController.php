<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Collaborateur;
use App\Models\Entreprise;

class CollaborateurController extends Controller
{
    public function __construct()
    {
        $this->authorizeResource(Collaborateur::class, 'collaborateur');
    }

    private function create_index_tab($collaborateurs=NULL)
    {
        if ($collaborateurs == NULL) {
            $collaborateurs = Collaborateur::all();
        }

        $entreprises = Entreprise::all();

        $result = array();

        foreach ($collaborateurs as $collaborateur) {
            $entreprise = Entreprise::find($collaborateur->entreprise_id);
            array_push($result, [
                'collaborateur' => $collaborateur,
                'entreprise' => $entreprise,
                'curr_nav' => 'collaborateur'
            ]);
        }
        return $result;
    }

    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $collab_entre = $this->create_index_tab();

        return view('collaborateurs.index', [
            'collab_entre' => $collab_entre,
            'curr_nav' => 'collaborateur'
        ]);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        $entreprises = Entreprise::all();

        return view('collaborateurs.create', [
            'curr_nav' => 'collaborateur',
            'entreprises' => $entreprises
        ]);
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        $validated = $request->validate([
            'civility' => 'required',
            'lastName' => 'required|alpha',
            'firstName' => 'required|alpha',
            'street' => 'required' . '|regex:~[0-9a-zA-Z\s]*~',
            'postalCode' => 'required|digits:5',
            'city' => 'required' . '|regex:~[a-zA-Z\s]*~',
            'phone' => 'nullable|unique:collaborateurs,phone|regex:~(\+33)[0-9]{9}~',
            'email' => 'required|unique:collaborateurs,email|email:rfc',
            'entreprise_id' => 'required|numeric',
        ]);

        $validated['phone'] = $validated['phone'];
        $collaborateur = Collaborateur::create($validated);

        return redirect()->route('collaborateur.show', [
            'collaborateur' => $collaborateur->id,
            'curr_nav' => 'collaborateur'
        ]);

    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show(Collaborateur $collaborateur)
    {
        $entreprise = Entreprise::find($collaborateur->entreprise_id);

        return view('collaborateurs.show', [
            'collaborateur' => $collaborateur,
            'entreprise' => $entreprise,
            'curr_nav' => 'collaborateur'
        ]);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit(Collaborateur $collaborateur)
    {
        $entreprises = Entreprise::all();
        $entreprise = Entreprise::find($collaborateur->entreprise_id);
        return view('collaborateurs.edit', [
            'collaborateur' => $collaborateur,
            'entreprise' => $entreprise,
            'entreprises' => $entreprises,
            'curr_nav' => 'collaborateur'
        ]);
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, Collaborateur $collaborateur)
    {
        $validated = $request->validate([
            'civility' => 'required',
            'lastName' => 'required|alpha',
            'firstName' => 'required|alpha',
            'street' => 'required' . '|regex:~[0-9a-zA-Z\s]*~',
            'postalCode' => 'required|digits:5',
            'city' => 'required' . '|regex:~[a-zA-Z\s]*~',
            'phone' => 'nullable|unique:collaborateurs,phone,' . $collaborateur->id . '|regex:~(\+33)[0-9]{9}~',
            'email' => 'required|unique:collaborateurs,email,' . $collaborateur->id . '|email:rfc',
            'entreprise_id' => 'required|numeric',
        ]);
        $collaborateur->civility = $validated['civility'];
        $collaborateur->lastName = $validated['lastName'];
        $collaborateur->firstName = $validated['firstName'];
        $collaborateur->street = $validated['street'];
        $collaborateur->postalCode = $validated['postalCode'];
        $collaborateur->city = $validated['city'];
        if(!is_null($validated['phone']))
            $validated['phone'] = $validated['phone'];
        $collaborateur->phone = $validated['phone'];
        $collaborateur->email = $validated['email'];
        $collaborateur->entreprise_id = $validated['entreprise_id'];
        $collaborateur->save();

        return redirect()->route('collaborateur.show', [
            'collaborateur' => $collaborateur,
            'curr_nav' => 'collaborateur'
        ]);
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy(Collaborateur $collaborateur)
    {
        $collaborateur->delete();

        return redirect()->route('collaborateur.index');
    }

    public function search(Request $request)
    {
        $search = $request->input('search');

        $posts = Collaborateur::query()
            ->where('firstName', 'LIKE', "%{$search}%")
            ->orWhere('lastName', 'LIKE', "%{$search}%")
            ->orWhere('phone', 'LIKE', "%{$search}%")
            ->orWhere('email', 'LIKE', "%{$search}%")
            ->get();
        $tab = $this->create_index_tab($posts);

        return view('collaborateurs.index', [
            'collab_entre' => $tab,
            'curr_nav' => 'collaborateur'
        ]);
    }
}
