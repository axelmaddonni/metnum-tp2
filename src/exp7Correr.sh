#!/usr/bin/env bash
echo "PageRank sin personalizacion"
./main experimentos/PageRank/in/exp7.in experimentos/PageRank/out/exp7.out
echo "PageRank con personalizacion: 129 en el historial"
./main experimentos/PageRank/in/exp7.in experimentos/PageRank/out/exp7Seg.out experimentos/PageRank/in/exp7Seg.pers
echo "PageRank con personalizacion: 130 hub en el historial"
./main experimentos/PageRank/in/exp7.in experimentos/PageRank/out/exp7Ter.out experimentos/PageRank/in/exp7Ter.pers
echo "PageRank con personalizacion: 131 hub en el historial"
./main experimentos/PageRank/in/exp7.in experimentos/PageRank/out/exp7Cto.out experimentos/PageRank/in/exp7Cto.pers
echo "PageRank con personalizacion: pagina arbitraria en el historial"
./main experimentos/PageRank/in/exp7.in experimentos/PageRank/out/exp7Rnd.out experimentos/PageRank/in/exp7Rnd.pers
