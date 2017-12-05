#!/usr/bin/env bash
echo "0 0.85 0 experimentos/PageRank/in/exp5.txt 0.0000001" > experimentos/PageRank/in/exp5PR.in
echo "1 0.85 0 experimentos/PageRank/in/exp5.txt 0.0000001" > experimentos/PageRank/in/exp5ID.in
./crearExp.py Hub 1 0.5 128 2 2 experimentos/PageRank/in/exp5.txt experimentos/PageRank/in/exp5.png
