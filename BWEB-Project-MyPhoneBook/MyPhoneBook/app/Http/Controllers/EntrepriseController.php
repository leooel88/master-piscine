<?php

namespace App\Http\Controllers;

use App\Models\Entreprise;
use Illuminate\Http\Request;

class EntrepriseController extends Controller
{

    public function __construct()
    {
        $this->authorizeResource(Entreprise::class, 'entreprise');
    }

    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $entreprises = Entreprise::all();

        return view('entreprises.index', [
            'entreprises' => $entreprises,
            'curr_nav' => 'entreprise'
        ]);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        return view('entreprises.create', [
            'curr_nav' => 'entreprise'
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
            'name' => 'required|unique:entreprises,name',
            'street' => 'required' . '|regex:~[0-9a-zA-Z\s]*~',
            'postalCode' => 'required|digits:5',
            'city' => 'required' . '|regex:~[a-zA-Z\s]*~',
            'phone' => 'nullable|unique:entreprises,phone|regex:~(\+33)[0-9]{9}~',
            'email' => 'required|unique:entreprises,email|email:rfc'
        ]);
        $entreprise = Entreprise::create($validated);

        return redirect()->route('entreprise.show', [
            'entreprise' => $entreprise,
            'curr_nav' => 'entreprise'
        ]);
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Entreprise  $entreprise
     * @return \Illuminate\Http\Response
     */
    public function show(Entreprise $entreprise)
    {
        return view('entreprises.show', [
            'entreprise' => $entreprise,
            'curr_nav' => 'entreprise'
        ]);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  \App\Models\Entreprise  $entreprise
     * @return \Illuminate\Http\Response
     */
    public function edit(Entreprise $entreprise)
    {
        return view('entreprises.edit', [
            'entreprise' => $entreprise,
            'curr_nav' => 'entreprise'
        ]);
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  \App\Models\Entreprise  $entreprise
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, Entreprise $entreprise)
    {
        $validated = $request->validate([
            'name' => 'required|unique:entreprises,name,' . $entreprise->id,
            'street' => 'required' . '|regex:~[0-9a-zA-Z\s]*~',
            'postalCode' => 'required|digits:5',
            'city' => 'required' . '|regex:~[a-zA-Z\s]*~',
            'phone' => 'nullable|unique:entreprises,phone,' . $entreprise->id . '|regex:~(\+33)[0-9]{9}~',
            'email' => 'required|unique:entreprises,email,' . $entreprise->id . '|email:rfc'
        ]);

        $entreprise->name = $validated['name'];
        $entreprise->street = $validated['street'];
        $entreprise->postalCode = $validated['postalCode'];
        $entreprise->city = $validated['city'];
        $entreprise->phone = $validated['phone'];
        $entreprise->email = $validated['email'];
        $entreprise->save();

        return redirect()->route('entreprise.show', [
            'entreprise' => $entreprise,
            'curr_nav' => 'entreprise'
        ]);
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Entreprise  $entreprise
     * @return \Illuminate\Http\Response
     */
    public function destroy(Entreprise $entreprise)
    {
        $entreprise->delete();

        return redirect()->route('entreprise.index');
    }

    public function search(Request $request)
    {
        $search = $request->input('search');

        $posts = Entreprise::query()
            ->where('name', 'LIKE', "%{$search}%")
            ->orWhere('city', 'LIKE', "%{$search}%")
            ->get();

        return view('entreprises.index', [
            'entreprises' => $posts,
            'curr_nav' => 'entreprise'
        ]);
    }
}
