@extends('layouts.default')

@section('main')

    <div class="flex items-center justify-center h-screen w-full bg-teal-lighter">
        <div class="w-7/12 bg-white rounded shadow-lg p-8 m-4">
        <h1 class="block w-full text-center text-grey-darkest mb-6 text-blue-900">Nouvelle entreprise</h1>
        @if ($errors->any())
            <div class="alert alert-danger">
                <ul>
                    @foreach ($errors->all() as $error)
                        <li>{{ $error }}</li>
                    @endforeach
                </ul>
            </div>
        @endif
        <form class="mb-4" action={{ route('entreprise.store') }} method="POST">
            @csrf
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="name" placeholder="Nom">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="street" placeholder="Rue">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="postalCode" placeholder="Code postal">
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
            <div class="flex flex-col items-center justify-center mb-4">
                <input class="m-2 px-4 py-1 w-80 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" type="submit" value="Créer l'entreprise">
            </div>
        </form>
        </div>
    </div>
@endsection