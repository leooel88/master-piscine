@extends('layouts.default')
@section('main')
    <div class="container flex justify-center mx-auto my-5">
        <div class="flex flex-col">
            <div class="px-4 py-2 flex flex-row justify-center content-center">
                <div class="px-4 py-2 text-sm text-gray-500">
                    <form action="{{route('search_collab')}}" method="get">
                        @csrf
                        <input type="text" placeholder="Recherche..." name="search">
                        <input class="px-4 py-1 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" type="submit" value="Recherche">
                    </form>
                </div>
                @if(Auth::user() && Auth::user()->role != 'user')
                    <div class="px-6 py-4 text-sm text-gray-500 flex items-center">
                        <a class="px-4 py-1 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" href="{{route('collaborateur.create')}}">Ajouter un collaborateur</a>
                    </div>
                @endif
            </div>
            <div class="w-full">
                <div class="border-b border-gray-200 shadow-xl">
                    <table>
                        <thead class="bg-gray-50">
                            <tr>
                                <th class="px-6 py-2 text-s text-gray-500">Nom</th>
                                <th class="px-6 py-2 text-s text-gray-500">Prénom</th>
                                <th class="px-6 py-2 text-s text-gray-500">Téléphone</th>
                                <th class="px-6 py-2 text-s text-gray-500">Email</th>
                                <th class="px-6 py-2 text-s text-gray-500">Nom de l'entreprise</th>
                                <th class="px-6 py-2 text-s text-gray-500">Téléphone de l'entreprise</th>
                                <th class="px-6 py-2 text-s text-gray-500"></th>
                            </tr>
                        </thead>
                        @if(!empty($collab_entre))
                            <tbody class="bg-white">
                                @foreach ($collab_entre as $curr_tab)
                                    <tr class="whitespace-nowrap">
                                        <td class="px-6 py-4 text-sm text-gray-500">{{ $curr_tab['collaborateur']['lastName'] }}</td>
                                        <td class="px-6 py-4 text-sm text-gray-500">{{ $curr_tab['collaborateur']['firstName'] }}</td>
                                        <td class="px-6 py-4 text-sm text-gray-500">{{ $curr_tab['collaborateur']['phone'] }}</td>
                                        <td class="px-6 py-4 text-sm text-gray-500">{{ $curr_tab['collaborateur']['email'] }}</td>
                                        <td class="px-6 py-4 text-sm text-gray-500">{{ $curr_tab['entreprise']['name'] }}</td>
                                        <td class="px-6 py-4 text-sm text-gray-500">{{ $curr_tab['entreprise']['phone'] }}</td>
                                        <td class="px-6 py-4 text-sm text-gray-500"><a class="px-4 py-1 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" href="{{ route('collaborateur.show', $curr_tab['collaborateur']) }}">Voir le collaborateur</a></td>
                                    </tr>
                                @endforeach
                            </tbody>
                        @else
                            <div>
                                <h2>Aucun résultat</h2>
                            </div>
                        @endif
                    </table>
                </div>
            </div>
        </div>
    </div>
@endsection