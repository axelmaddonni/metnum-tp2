#!/bin/bash
echo "0 0.085 0 experimentos/PageRank/in/exp2s10.txt     0.00000001" > experimentos/PageRank/in/exp2s10.in
echo "0 0.085 0 experimentos/PageRank/in/exp2s50.txt     0.00000001" > experimentos/PageRank/in/exp2s50.in
echo "0 0.085 0 experimentos/PageRank/in/exp2s100.txt    0.00000001" > experimentos/PageRank/in/exp2s100.in
echo "0 0.085 0 experimentos/PageRank/in/exp2s250.txt    0.00000001" > experimentos/PageRank/in/exp2s250.in
echo "0 0.085 0 experimentos/PageRank/in/exp2s1000.txt   0.00000001" > experimentos/PageRank/in/exp2s1000.in
echo "0 0.085 0 experimentos/PageRank/in/exp2s2500.txt   0.00000001" > experimentos/PageRank/in/exp2s2500.in
echo "0 0.085 0 experimentos/PageRank/in/exp2s5000.txt   0.00000001" > experimentos/PageRank/in/exp2s5000.in
echo "0 0.085 0 experimentos/PageRank/in/exp2s10000.txt  0.00000001" > experimentos/PageRank/in/exp2s10000.in
echo "0 0.085 0 experimentos/PageRank/in/exp2s25000.txt  0.00000001" > experimentos/PageRank/in/exp2s25000.in
./crearExp.py Distribuido 1000 1 1 experimentos/PageRank/in/exp2s10.txt        experimentos/PageRank/in/exp2s10.png
./crearExp.py Distribuido 1000 2 2 experimentos/PageRank/in/exp2s50.txt        experimentos/PageRank/in/exp2s50.png
./crearExp.py Distribuido 1000 4 4 experimentos/PageRank/in/exp2s100.txt       experimentos/PageRank/in/exp2s100.png
./crearExp.py Distribuido 1000 8 8 experimentos/PageRank/in/exp2s250.txt       No
./crearExp.py Distribuido 1000 16  16 experimentos/PageRank/in/exp2s1000.txt   No
./crearExp.py Distribuido 1000 32  32 experimentos/PageRank/in/exp2s2500.txt   No
./crearExp.py Distribuido 1000 64  64 experimentos/PageRank/in/exp2s5000.txt   No
./crearExp.py Distribuido 1000 128 128 experimentos/PageRank/in/exp2s10000.txt No
