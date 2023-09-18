@extends('layouts.default')

@section('main')
    <h1>Hello World</h1>

    <form action="/create_produit" method="POST">
        @csrf
        @method('PUT')

        @if ($errors->any())
            <div class="alert alert-danger">
                <ul>
                    @foreach ($errors->all() as $error)
                        <li>{{ $error }}</li>
                    @endforeach
                </ul>
            </div>
        @endif

        <input type="text" name="productName" placeholder="Product's name">

        <input type="textarea" name="description" placeholder="Description">

        <input type="number" name="price" placeholder="Price">

        <label for="isAvailable">Availability</label>
        <input type="checkbox" id="isAvailable" name="isAvailable">

        <input type="submit" value="Create product">
    </form>
@endsection