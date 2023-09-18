#!/bin/bash

ar -rc ./lib/my/libmy.a ./lib/my/*o
ranlib ./lib/my/libmy.a
