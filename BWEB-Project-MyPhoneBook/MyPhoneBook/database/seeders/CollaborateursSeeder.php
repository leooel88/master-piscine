<?php

namespace Database\Seeders;

use App\Models\Collaborateur;
use Illuminate\Database\Seeder;

class CollaborateursSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        Collaborateur::factory()
            ->count(1000)
            ->create();
    }
}
