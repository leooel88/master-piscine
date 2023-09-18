<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Collaborateur extends Model
{
    use HasFactory;

    public $timestamps = false;

    protected $fillable = [
        'civility',
        'lastName',
        'firstName',
        'street',
        'postalCode',
        'city',
        'phone',
        'email',
        'entreprise_id'
    ];
}
