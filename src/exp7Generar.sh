#!/usr/bin/env bash
echo "0 0.85 0 experimentos/PageRank/in/exp7.txt 0.0000001" > experimentos/PageRank/in/exp7.in
./crearExp.py Hub 3 0.75 128 1 1 experimentos/PageRank/in/exp7.txt experimentos/PageRank/in/exp7.png
