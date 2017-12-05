#!/bin/bash
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.100000000000000" > experimentos/PageRank/in/exp4s1.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.010000000000000" > experimentos/PageRank/in/exp4s2.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.001000000000000" > experimentos/PageRank/in/exp4s3.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000100000000000" > experimentos/PageRank/in/exp4s4.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000010000000000" > experimentos/PageRank/in/exp4s5.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000001000000000" > experimentos/PageRank/in/exp4s6.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000000100000000" > experimentos/PageRank/in/exp4s7.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000000010000000" > experimentos/PageRank/in/exp4s8.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000000001000000" > experimentos/PageRank/in/exp4s9.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000000000100000" > experimentos/PageRank/in/exp4sA.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000000000010000" > experimentos/PageRank/in/exp4sB.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000000000001000" > experimentos/PageRank/in/exp4sC.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000000000000100" > experimentos/PageRank/in/exp4sD.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000000000000010" > experimentos/PageRank/in/exp4sE.in
echo "0 0.85 0 experimentos/PageRank/in/exp4.txt 0.000000000000001" > experimentos/PageRank/in/exp4sF.in
./crearExp.py Distribuido 10000 4 4 experimentos/PageRank/in/exp4.txt No
