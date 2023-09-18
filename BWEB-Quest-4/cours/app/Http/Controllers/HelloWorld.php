<?php

namespace App\Http\Controllers;

use App\Models\Produit;
use Illuminate\Auth\Events\Validated;
use Illuminate\Http\Request;

class HelloWorld extends Controller
{

    public function show() {
        return view('hello_world');
    }

    public function store(Request $request) {
        $validated = $request->validate([
            'productName' => 'required',
            'description' => 'required',
            'price' => 'integer|required'
        ]);

        $validated['isAvailable'] = isset($request->isAvailable[0]) ? 1 : 0;

        Produit::create($validated);

        return 'Product successfully created!';
    }
}
