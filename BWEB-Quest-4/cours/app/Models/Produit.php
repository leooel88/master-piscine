<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Produit extends Model
{
    use HasFactory;

    protected $fillable = [
        'productName',
        'description',
        'price',
        'isAvailable'
    ];

    public $timestamps = false;

    protected $table = 'produit';
}
