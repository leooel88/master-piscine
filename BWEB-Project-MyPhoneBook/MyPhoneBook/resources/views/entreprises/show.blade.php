@extends('layouts.default')

@section('main')
    <div class="relative top-5 flex justify-center">
        <h2 class="text-3xl text-indigo-900">Informations sur {{ $entreprise['name'] }}</h2>
    </div>
    <div class="relative top-5 container flex justify-center mx-auto my-5">
        <div class="flex flex-col">
            <div class="w-full">
                <div class="border-b border-gray-200 shadow-xl">
                    <table>
                        <thead class="bg-gray-50">
                            <tr>
                                <th class="px-6 py-2 text-s text-gray-500">Id</th>
                                <th class="px-6 py-2 text-s text-gray-500">Nom</th>
                                <th class="px-6 py-2 text-s text-gray-500">Rue</th>
                                <th class="px-6 py-2 text-s text-gray-500">Code postal</th>
                                <th class="px-6 py-2 text-s text-gray-500">Ville</th>
                                <th class="px-6 py-2 text-s text-gray-500">Numéro de téléphone</th>
                                <th class="px-6 py-2 text-s text-gray-500">Email</th>
                            </tr>
                        </thead>
                        <tbody class="bg-white">
                            <tr>
                                <td class="px-6 py-4 text-sm text-gray-500">{{ $entreprise['id'] }}</td>
                                <td class="px-6 py-4">{{ $entreprise['name'] }}</td>
                                <td class="px-6 py-4 text-sm text-gray-500">{{ $entreprise['street'] }}</td>
                                <td class="px-6 py-4 text-sm text-gray-500">{{ $entreprise['postalCode'] }}</td>
                                <td class="px-6 py-4 text-sm text-gray-500">{{ $entreprise['city'] }}</td>
                                <td class="px-6 py-4 text-sm text-gray-500">{{ $entreprise['phone'] }}</td>
                                <td class="px-6 py-4 text-sm text-gray-500">{{ $entreprise['email'] }}</td>
                            </tr>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </div>
    <div class="relative top-5 flex flex-row justify-center">
        @can('update', $entreprise)
            <a class="m-5 px-4 py-1 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" href="{{ route('entreprise.edit', $entreprise) }}">
                <button>Editer</button>
            </a>
        @endcan

        @can('delete', $entreprise)
            <form class="m-5" action="{{ route('entreprise.destroy', $entreprise) }}" method="post">
                @csrf
                @method('DELETE')
                <button class="px-4 py-1 text-sm text-white bg-red-900 hover:bg-red-800 rounded" type="submit">Supprimer</button>
            </form>
        @endcan
    </div>
@endsection
