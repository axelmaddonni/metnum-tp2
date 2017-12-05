#!/usr/bin/env bash
echo "S10" > experimentos/PageRank/out/exp2.time
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp2s10.in     experimentos/PageRank/out/exp2s10.out; done; } 2>>     experimentos/PageRank/out/exp2.time;
echo "S50" >> experimentos/PageRank/out/exp2.time
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp2s50.in     experimentos/PageRank/out/exp2s50.out; done; } 2>>     experimentos/PageRank/out/exp2.time;
echo "S100" >> experimentos/PageRank/out/exp2.time
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp2s100.in    experimentos/PageRank/out/exp2s100.out; done; } 2>>    experimentos/PageRank/out/exp2.time;
echo "S250" >> experimentos/PageRank/out/exp2.time        
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp2s250.in    experimentos/PageRank/out/exp2s250.out; done; } 2>>    experimentos/PageRank/out/exp2.time;
echo "S1000" >> experimentos/PageRank/out/exp2.time      
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp2s1000.in   experimentos/PageRank/out/exp2s1000.out; done; } 2>>   experimentos/PageRank/out/exp2.time;
echo "S2500" >> experimentos/PageRank/out/exp2.time       
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp2s2500.in   experimentos/PageRank/out/exp2s2500.out; done; } 2>>   experimentos/PageRank/out/exp2.time;
echo "S5000" >> experimentos/PageRank/out/exp2.time      
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp2s5000.in   experimentos/PageRank/out/exp2s5000.out; done; } 2>>   experimentos/PageRank/out/exp2.time;
echo "S10000" >> experimentos/PageRank/out/exp2.time    
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp2s10000.in  experimentos/PageRank/out/exp2s10000.out; done; } 2>>  experimentos/PageRank/out/exp2.time;
