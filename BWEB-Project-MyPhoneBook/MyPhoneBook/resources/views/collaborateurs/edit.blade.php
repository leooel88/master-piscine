@extends('layouts.default')

@section('main')

    <div class="relative top-10 flex items-center justify-center h-screen w-full bg-teal-lighter">
        <div class="w-7/12 bg-white rounded shadow-lg p-8 m-4">
        <h1 class="block w-full text-center text-grey-darkest mb-6 text-blue-900">Edition du collaborateur</h1>
        @if ($errors->any())
            <div class="alert alert-danger">
                <ul>
                    @foreach ($errors->all() as $error)
                        <li>{{ $error }}</li>
                    @endforeach
                </ul>
            </div>
        @endif
        <form class="mb-4" action={{ route('collaborateur.update', $collaborateur->id) }} method="post">
            @csrf
            @method('PUT')
            <div class="grid grid-cols-5 grid-rows-2 mb-5">
                <div class="row-span-2 h-full w-full border border-gray-500 mb-3 flex flex-col">
                    <div class="relative left-3 text-gray-500">
                        <p>Genre:</p>
                    </div>
                    <div class="">
                        <div class="">
                            <div class="mx-5 text-gray-500">
                                <input type="radio" id="male" name="civility" value="male"
                                    @if ($collaborateur->civility === 'male')
                                        checked
                                    @endif
                                >
                                <label for="male">Homme</label>
                            </div>
                            <div class="mx-5 text-gray-500">
                                <input type="radio" id="female" name="civility" value="female"
                                    @if ($collaborateur->civility === 'female')
                                            checked
                                    @endif
                                >
                                <label for="female">Femme</label>
                            </div>
                            <div class="mx-5 text-gray-500">
                                <input type="radio" id="custom" name="civility" value="custom"
                                    @if ($collaborateur->civility === 'custom')
                                            checked
                                    @endif
                                >
                                <label for="custom">Non binaire</label>
                            </div>
                            <div class="mx-5 text-gray-500">
                                <input type="radio" id="custom" name="civility" value="unspecified"
                                    @if ($collaborateur->civility === 'unspecified')
                                            checked
                                    @endif
                                >
                                <label for="unspecified">Non précisé</label>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="ml-4 w-full col-span-3 flex flex-col mb-4">
                    <input class="border py-2 px-3 text-grey-darkest" type="text" name="lastName" placeholder="Nom" value="{{ $collaborateur->lastName }}">
                </div>
                <div class="ml-4 w-full col-span-3 flex flex-col mb-4">
                    <input class="border py-2 px-3 text-grey-darkest" type="text" name="firstName" placeholder="Prénom" value="{{ $collaborateur->firstName }}">
                </div>
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="street" placeholder="Rue" value="{{ $collaborateur->street }}">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="postalCode" placeholder="Code Postal" value="{{ $collaborateur->postalCode }}">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="city" placeholder="Ville" value="{{ $collaborateur->city }}">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="phone" placeholder="Numéro de téléphone" value="+33{{ substr($collaborateur->phone, 3, 12) }}">
            </div>
            <div class="flex flex-col mb-4">
                <input class="border py-2 px-3 text-grey-darkest" type="text" name="email" placeholder="Email" value="{{ $collaborateur->email }}">
            </div>
            <div class="flex flex-col mb-4">
                <select name="entreprise_id">
                    <option value="{{ $entreprise->id }}" selected>{{ $entreprise->name }}</option>
                    @foreach ($entreprises as $curr_entreprise)
                        <option value="{{$curr_entreprise->id}}">{{$curr_entreprise->name}}</option>
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