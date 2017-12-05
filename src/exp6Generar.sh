#!/usr/bin/env bash
echo "0 0.95 0 experimentos/PageRank/in/exp6s64.txt 0.0000001" > experimentos/PageRank/in/exp6PRs64.in
echo "1 0.95 0 experimentos/PageRank/in/exp6s64.txt 0.0000001" > experimentos/PageRank/in/exp6IDs64.in
echo "0 0.95 0 experimentos/PageRank/in/exp6s128.txt 0.0000001" > experimentos/PageRank/in/exp6PRs128.in
echo "1 0.95 0 experimentos/PageRank/in/exp6s128.txt 0.0000001" > experimentos/PageRank/in/exp6IDs128.in
echo "0 0.95 0 experimentos/PageRank/in/exp6s256.txt 0.0000001" > experimentos/PageRank/in/exp6PRs256.in
echo "1 0.95 0 experimentos/PageRank/in/exp6s256.txt 0.0000001" > experimentos/PageRank/in/exp6IDs256.in
echo "0 0.05 0 experimentos/PageRank/in/exp6s256.txt 0.0000001" > experimentos/PageRank/in/exp6PRs256c0-05.in
./crearExp.py Ataque 16 64 3 5  experimentos/PageRank/in/exp6s64.txt  experimentos/PageRank/in/exp6s64.png
./crearExp.py Ataque 16 128 3 5 experimentos/PageRank/in/exp6s128.txt experimentos/PageRank/in/exp6s128.png
./crearExp.py Ataque 16 256 3 5 experimentos/PageRank/in/exp6s256.txt experimentos/PageRank/in/exp6s256.png
