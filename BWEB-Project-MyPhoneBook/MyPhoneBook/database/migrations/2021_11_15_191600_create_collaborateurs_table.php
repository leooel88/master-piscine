<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateCollaborateursTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('collaborateurs', function (Blueprint $table) {
            $table->id();
            $table->enum('civility', ['male', 'female', 'custom', 'unspecified']);
            $table->string('lastName', 25);
            $table->string('firstName', 25);
            $table->string('street', 100);
            $table->string('postalCode', 5);
            $table->string('city', 170);
            $table->string('phone', 12)->unique()->nullable();
            $table->string('email')->unique();
            $table->foreignId('entreprise_id')
                    ->constrained()
                    ->onUpdate('cascade')
                    ->onDelete('cascade');
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('collaborateurs');
    }
}
