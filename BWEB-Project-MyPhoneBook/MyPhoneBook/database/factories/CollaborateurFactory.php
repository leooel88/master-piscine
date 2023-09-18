<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;

class CollaborateurFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array
     */
    public function definition()
    {
        return [
            'civility' => $this->faker->numberBetween(1, 4),
            'lastName' => $this->faker->lastName(),
            'firstName' => $this->faker->firstName(),
            'street' => $this->faker->streetAddress(),
            'postalCode' => $this->faker->regexify('[0-9]{5}'),
            'city' => $this->faker->city(),
            'phone' => $this->faker->unique()->regexify('(\+33)[0-9]{9}'),
            'email' => $this->faker->unique()->safeEmail(),
            'entreprise_id' => $this->faker->numberBetween(1,100)
            ];
    }
}
