#!/bin/bash
echo "0 0.95 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s1.in
echo "0 0.90 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s2.in
echo "0 0.85 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s3.in
echo "0 0.80 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s4.in
echo "0 0.75 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s5.in
echo "0 0.70 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s6.in
echo "0 0.65 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s7.in
echo "0 0.60 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s8.in
echo "0 0.55 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s9.in
echo "0 0.50 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3sA.in
echo "0 0.45 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3sB.in
echo "0 0.40 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3sC.in
echo "0 0.35 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3sD.in
echo "0 0.30 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3sE.in
echo "0 0.25 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3sF.in
echo "0 0.20 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s10.in
echo "0 0.15 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s11.in
echo "0 0.10 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s12.in
echo "0 0.05 0 experimentos/PageRank/in/exp3.txt     0.00000001" > experimentos/PageRank/in/exp3s13.in
./crearExp.py Distribuido 10000 4 4 experimentos/PageRank/in/exp3.txt No
