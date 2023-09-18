@extends('layouts.default')

@section('main')

    <div class="relative top-10 flex items-center justify-center h-screen w-full bg-teal-lighter">
        <div class="w-7/12 bg-white rounded shadow-lg p-8 m-4">
        <h1 class="block w-full text-center text-grey-darkest mb-6 text-blue-900">Nouveau collaborateur</h1>
        @if ($errors->any())
            <div class="alert alert-danger">
                <ul>
                    @foreach ($errors->all() as $error)
                        <li>{{ $error }}</li>
                    @endforeach
                </ul>
            </div>
        @endif
        <form class="mb-4" action={{ route('collaborateur.store') }} method="POST">
            @csrf
            <div class="grid grid-cols-5 grid-rows-2 mb-5">
                <div class="row-span-2 h-full w-full border border-gray-500 mb-3 flex flex-col">
                    <div class="relative left-3 text-gray-500">
                        <p>Genre:</p>
                    </div>
                    <div class="">
                        <div class="">
                            <div class="mx-5 text-gray-500">
                                <input type="radio" id="male" name="civility" value="male">
                                <label for="male">Homme</label>
                            </div>
                            <div class="mx-5 text-gray-500">
                                <input type="radio" id="female" name="civility" value="female">
                                <label for="female">Femme</label>
                            </div>
                            <div class="mx-5 text-gray-500">
                                <input type="radio" id="custom" name="civility" value="custom">
                                <label for="custom">Non binaire</label>
                            </div>
                            <div class="mx-5 text-gray-500">
                                <input type="radio" id="custom" name="civility" value="unspecified" checked>
                                <label for="unspecified">Non précisé</label>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="ml-4 w-full col-span-3 flex flex-col mb-4">
                    <input class="border py-2 px-3 text-grey-darkest" type="text" name="lastName" placeholder="Nom">
                </div>
                <div class="ml-4 w-full col-span-3 flex flex-col mb-4">
                    <input class="border py-2 px-3 text-grey-darkest" type="text" name="firstName" placeholder="Prénom">
                </div>
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="street" placeholder="Rue">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="postalCode" placeholder="Code Postal">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="city" placeholder="Ville">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="phone" placeholder="Numéro de téléphone">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="email" placeholder="Email">
            </div>
            <div class="flex flex-col mb-4">
                <select name="entreprise_id">
                    <option value="">--Veuillez choisir une entreprise--</option>
                    @foreach ($entreprises as $entreprise)
                        <option value="{{$entreprise->id}}">{{$entreprise->name}}</option>
                    @endforeach
                </select>
            </div>
            <div class="flex flex-col items-center justify-center mb-4">
                <input class="m-2 px-4 py-1 w-80 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" type="submit" value="Créer le collaborateur">
            </div>
        </form>
        </div>
    </div>
@endsection