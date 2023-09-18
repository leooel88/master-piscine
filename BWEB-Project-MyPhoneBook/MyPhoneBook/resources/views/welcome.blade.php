@include('layouts.default')
<div class="flex flex-col items-center justify-center ">
    <div class="text-4xl text-blue-900">
        <h1>Bienvenue sur votre Phone Book</h1>
    </div>

    <div>
        <h1 class="text-l text-blue-900">Votre liste d'entreprises partenaires et de collaborateurs</h1>
    </div>

    <div class="flex flex-row">
        <div class="flex flex-col items-center justify-center text-xl text-blue-900">
            <h1>Visualisez votre liste de contacts</h1>
            <div class="w-4/5 h-4/5 shadow-2xl m-5">
                <img src="{{ asset('/images/list.png') }}">
            </div>
        </div>

        <div class="flex flex-col items-center justify-center text-xl text-blue-900">
            <h1>Créez et modifiez les informations</h1>
            <div class="w-4/5 h-4/5 shadow-2xl m-5">
                <img src="{{ asset('/images/edit.png') }}">
            </div>
        </div>
    </div>
</div>

