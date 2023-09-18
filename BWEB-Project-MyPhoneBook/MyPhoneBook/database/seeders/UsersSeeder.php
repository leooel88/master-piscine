<?php

namespace Database\Seeders;

use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Hash;
use Illuminate\Database\Seeder;

class UsersSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        DB::table('users')->insert([
            'login' => 'admin',
            'password' => Hash::make('admin'),
            'role' => 'admin'
        ]);

        DB::table('users')->insert([
            'login' => 'user',
            'password' => Hash::make('user'),
            'role' => 'user'
        ]);

        DB::table('users')->insert([
            'login' => 'gestionnaire',
            'password' => Hash::make('gestionnaire'),
            'role' => 'gest'
        ]);
    }
}
