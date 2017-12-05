#!/usr/bin/env bash
echo "PageRank: s64"
./main experimentos/PageRank/in/exp6PRs64.in  experimentos/PageRank/out/exp6PRs64.out
echo "In-Deg: s64"                                                               
./main experimentos/PageRank/in/exp6IDs64.in  experimentos/PageRank/out/exp6IDs64.out
echo "PageRank: s128"                                                             
./main experimentos/PageRank/in/exp6PRs128.in experimentos/PageRank/out/exp6PRs128.out
echo "In-Deg: s128"                                                               
./main experimentos/PageRank/in/exp6IDs128.in experimentos/PageRank/out/exp6IDs128.out
echo "PageRank: s256"                                                             
./main experimentos/PageRank/in/exp6PRs256.in experimentos/PageRank/out/exp6PRs256.out
echo "In-Deg: s256"                                                               
./main experimentos/PageRank/in/exp6IDs256.in experimentos/PageRank/out/exp6IDs256.out
