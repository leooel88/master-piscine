<?php

use App\Http\Controllers\EntrepriseController;
use App\Models\Entreprise;
use App\Http\Controllers\CollaborateurController;
use App\Http\Controllers\UserController;
use Illuminate\Support\Facades\Route;
use Illuminate\Support\Facades\Gate;
use App\Http\Middleware\EnsureIsLog;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
})->name('welcome');

Route::get('/dashboard', function () {
    return view('dashboard');
})->middleware(['auth'])->name('dashboard');

Route::get('entreprise/search', [EntrepriseController::class, 'search'])->name('search_entre');

Route::resource('entreprise', EntrepriseController::class)->middleware(EnsureIsLog::class);

Route::get('collaborateur/search', [CollaborateurController::class, 'search'])->name('search_collab');

Route::resource('collaborateur', CollaborateurController::class)->middleware(EnsureIsLog::class);

Route::get('user/search', [UserController::class, 'search'])->name('search_user');

Route::resource('user', UserController::class)->middleware(EnsureIsLog::class);


require __DIR__.'/auth.php';
