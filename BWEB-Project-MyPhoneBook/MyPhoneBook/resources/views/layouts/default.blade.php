<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>My Phone Book</title>

    <link rel="stylesheet" href="{{ asset('css/app.css') }}">
</head>
<body>
    <header class="bg-gray-100 grid grid-cols-5 gap-3 sticky top-0 z-50">
        <div class="flex justify-start items-center px-10">
            <a class="text-3xl text-blue-900 hover:text-blue-800" href="{{ route('welcome') }}">My Phone Book</a>
        </div>

        <div class="col-span-2 flex justify-start items-center px-10">
            @if (!isset($curr_nav))
                <div>
                    <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('entreprise.index') }}">Entreprise</a>
                </div>
                <div>
                    <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('collaborateur.index') }}">Collaborateur</a>
                </div>
                @if(Auth::user() && Auth::user()->role === 'admin')
                    <div>
                        <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('user.index') }}">Utilisateur</a>
                    </div>
                @endif
            @else
                @if ($curr_nav === 'entreprise')
                    <div class="h-full flex justify-center items-center border-b-4 border-blue-900">
                        <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('entreprise.index') }}">Entreprise</a>
                    </div>
                    <div>
                        <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('collaborateur.index') }}">Collaborateur</a>
                    </div>
                    @if(Auth::user() && Auth::user()->role === 'admin')
                        <div>
                            <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('user.index') }}">Utilisateur</a>
                        </div>
                    @endif
                @else
                    @if ($curr_nav === 'collaborateur')
                        <div>
                            <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('entreprise.index') }}">Entreprise</a>
                        </div>
                        <div class="h-full flex justify-center items-center border-b-4 border-blue-900">
                            <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('collaborateur.index') }}">Collaborateur</a>
                        </div>
                        @if(Auth::user() && Auth::user()->role === 'admin')
                            <div>
                                <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('user.index') }}">Utilisateur</a>
                            </div>
                        @endif
                    @else
                        <div>
                            <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('entreprise.index') }}">Entreprise</a>
                        </div>
                        <div>
                            <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('collaborateur.index') }}">Collaborateur</a>
                        </div>
                        @if(Auth::user() && Auth::user()->role === 'admin')
                            <div class="h-full flex justify-center items-center border-b-4 border-blue-900">
                                <a class="mx-5 text-1xl text-blue-900 hover:text-blue-800" href="{{ route('user.index') }}">Utilisateur</a>
                            </div>
                        @endif
                    @endif
                @endif
            @endif

        </div>

        @if (Route::has('login'))
            <div class="col-span-2 flex justify-end px-10">

                @auth
                    <a class="relative m-5 text-blue-900 hover:text-blue-800" href="{{ url('/dashboard') }}">Dashboard</a>
                @else
                    <a class="realtive m-5 text-blue-900 hover:text-blue-800" href="{{ route('login') }}">Log in</a>

                    @if (Route::has('register'))
                        <a class="realtive m-5 text-blue-900 hover:text-blue-800" href="{{ route('register') }}">Register</a>
                    @endif
                @endauth

            </div>
        @endif

    </header>
    <main class="relative">
        @yield('main')
    </main>
</body>
</html>