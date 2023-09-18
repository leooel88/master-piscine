@extends('layouts.default')

@section('main')
    <div class="relative top-5 flex justify-center">
        <h2 class="text-3xl text-indigo-900">Informations sur {{ $user['login'] }}</h2>
    </div>
    <div class="relative top-5 container flex justify-center mx-auto my-5">
        <div class="flex flex-col">
            <div class="w-full">
                <div class="border-b border-gray-200 shadow-xl">
                    <table>
                        <thead class="bg-gray-50">
                            <tr>
                                <th class="px-6 py-2 text-s text-gray-500">Login</th>
                                <th class="px-6 py-2 text-s text-gray-500">Email</th>
                                <th class="px-6 py-2 text-s text-gray-500">Role</th>
                            </tr>
                        </thead>
                        <tbody class="bg-white">
                            <tr>
                                <td class="px-6 py-4">{{ $user['login'] }}</td>
                                <td class="px-6 py-4 text-sm text-gray-500">{{ $user['email'] }}</td>
                                <td class="px-6 py-4">{{ $user['role'] }}</td>
                            </tr>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </div>
    <div class="relative top-5 flex flex-row justify-center">
        @can('update', $user)
            <a class="m-5 px-4 py-1 text-sm text-white bg-blue-900 hover:bg-blue-800 rounded" href="{{ route('user.edit', $user) }}">
                <button>Editer</button>
            </a>
        @endcan

        @can('delete', $user)
            <form class="m-5" action="{{ route('user.destroy', $user) }}" method="post">
                @csrf
                @method('DELETE')
                <button class="px-4 py-1 text-sm text-white bg-red-900 hover:bg-red-800 rounded" type="submit">Supprimer</button>
            </form>
        @endcan
    </div>
@endsection

