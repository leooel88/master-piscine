@extends('layouts.default')
@section('main')
    <h2>Modification du role de  {{ $user['login'] }}:</h2>  
    @if ($errors->any())
    <div class="alert alert-danger">
        <ul>
            @foreach ($errors->all() as $error)
                <li>{{ $error }}</li>
            @endforeach
        </ul>
    </div>
    @endif

    <form action={{ route('user.update', $user->id) }} method="POST">
        @csrf
        @method('PUT')

        <p>Role:</p>
        <div>
            <input type="radio" id="admin" name="role" value="admin">
            <label for="admin">Administrateur</label>
        </div>
        <div>
            <input type="radio" id="gest" name="role" value="gest">
            <label for="gest">Gestionnaire</label>
        </div>
        <div>
            <input type="radio" id="user" name="role" value="user">
            <label for="user">Utilisateur</label>
        </div>

        <button>Modifer</button>
    </form>
@endsection