@extends('layouts.default')
@section('main')
    <div class="container flex justify-center mx-auto my-5">
        <div class="flex flex-col">
            <div class="px-4 py-2 flex flex-row justify-center content-center">
                <div class="px-4 py-2 text-sm text-gray-500">
                    <form action="{{route('search_user')}}" method="get">
                        @csrf
                        <input type="text" placeholder="Recherche..." name="search">
                        <input class="px-4 py-1 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" type="submit" value="Recherche">
                    </form>
                </div>
                @can('create', User::class)
                    <div class="px-6 py-4 text-sm text-gray-500 flex items-center">
                        <a class="px-4 py-1 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" href="{{route('user.create')}}">Ajouter un utilisateur</a>
                    </div>
                @endcan
                
            </div>
            <div class="w-full">
                <div class="border-b border-gray-200 shadow-xl">
                    <table>
                        <thead class="bg-gray-50">
                            <tr>
                                <th class="px-6 py-2 text-s text-gray-500">Login</th>
                                <th class="px-6 py-2 text-s text-gray-500">Email</th>
                                <th class="px-6 py-2 text-s text-gray-500">Rôle</th>
                                <th class="px-6 py-2 text-s text-gray-500"></th>
                            </tr>
                        </thead>
                        @if($users->isNotEmpty())
                            <tbody class="bg-white">
                                @foreach ($users as $user)
                                    <tr class="whitespace-nowrap">
                                        <td class="px-6 py-4">{{ $user->login }}</td>
                                        <td class="px-6 py-4 text-sm text-gray-500">{{ $user->email }}</td>
                                        <td class="px-6 py-4 text-sm text-gray-500">{{ $user->role }}</td>
                                        <td class="px-6 py-4 text-sm text-gray-500"><a class="px-4 py-1 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" href="{{ route('user.show', $user) }}">Voir l'utilisateur</a></td>
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