<?php

namespace Database\Factories;

use Illuminate\Database\Eloquent\Factories\Factory;

class EntrepriseFactory extends Factory
{
    /**
     * Define the model's default state.
     *
     * @return array
     */
    public function definition()
    {
        return [
            'name' => $this->faker->unique()->company(),
            'street' => $this->faker->streetAddress(),
            'postalCode' => $this->faker->regexify('[0-9]{5}'),
            'city' => $this->faker->city(),
            'phone' => $this->faker->unique()->regexify('(\+33)[0-9]{9}'),
            'email' => $this->faker->unique()->safeEmail()
        ];
    }
}
