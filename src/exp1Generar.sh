#!/bin/bash
echo "0 0.085 0 experimentos/PageRank/in/exp1s10.txt     0.00000001" > experimentos/PageRank/in/exp1s10.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s50.txt     0.00000001" > experimentos/PageRank/in/exp1s50.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s100.txt    0.00000001" > experimentos/PageRank/in/exp1s100.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s250.txt    0.00000001" > experimentos/PageRank/in/exp1s250.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s1000.txt   0.00000001" > experimentos/PageRank/in/exp1s1000.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s2500.txt   0.00000001" > experimentos/PageRank/in/exp1s2500.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s5000.txt   0.00000001" > experimentos/PageRank/in/exp1s5000.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s10000.txt  0.00000001" > experimentos/PageRank/in/exp1s10000.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s25000.txt  0.00000001" > experimentos/PageRank/in/exp1s25000.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s50000.txt  0.00000001" > experimentos/PageRank/in/exp1s50000.in
echo "0 0.085 0 experimentos/PageRank/in/exp1s100000.txt 0.00000001" > experimentos/PageRank/in/exp1s100000.in
./crearExp.py Distribuido 10     4 4 experimentos/PageRank/in/exp1s10.txt  experimentos/PageRank/in/exp1s10.png
./crearExp.py Distribuido 50     4 4 experimentos/PageRank/in/exp1s50.txt  experimentos/PageRank/in/exp1s50.png
./crearExp.py Distribuido 100    4 4 experimentos/PageRank/in/exp1s100.txt experimentos/PageRank/in/exp1s100.png
./crearExp.py Distribuido 250    4 4 experimentos/PageRank/in/exp1s250.txt experimentos/PageRank/in/exp1s250.png
./crearExp.py Distribuido 1000   4 4 experimentos/PageRank/in/exp1s1000.txt No
./crearExp.py Distribuido 2500   4 4 experimentos/PageRank/in/exp1s2500.txt No
./crearExp.py Distribuido 5000   4 4 experimentos/PageRank/in/exp1s5000.txt No
./crearExp.py Distribuido 10000  4 4 experimentos/PageRank/in/exp1s10000.txt No
./crearExp.py Distribuido 25000  4 4 experimentos/PageRank/in/exp1s25000.txt No
./crearExp.py Distribuido 50000  4 4 experimentos/PageRank/in/exp1s50000.txt No
./crearExp.py Distribuido 100000 4 4 experimentos/PageRank/in/exp1s100000.txt No
