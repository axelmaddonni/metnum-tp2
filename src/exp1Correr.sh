#!/usr/bin/env bash
echo "S10" > experimentos/PageRank/out/exp1.time
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s10.in     experimentos/PageRank/out/exp1s10.out; done; } 2>>     experimentos/PageRank/out/exp1.time;
echo "S50" >> experimentos/PageRank/out/exp1.time
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s50.in     experimentos/PageRank/out/exp1s50.out; done; } 2>>     experimentos/PageRank/out/exp1.time;
echo "S100" >> experimentos/PageRank/out/exp1.time
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s100.in    experimentos/PageRank/out/exp1s100.out; done; } 2>>    experimentos/PageRank/out/exp1.time;
echo "S250" >> experimentos/PageRank/out/exp1.time        
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s250.in    experimentos/PageRank/out/exp1s250.out; done; } 2>>    experimentos/PageRank/out/exp1.time;
echo "S1000" >> experimentos/PageRank/out/exp1.time      
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s1000.in   experimentos/PageRank/out/exp1s1000.out; done; } 2>>   experimentos/PageRank/out/exp1.time;
echo "S2500" >> experimentos/PageRank/out/exp1.time       
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s2500.in   experimentos/PageRank/out/exp1s2500.out; done; } 2>>   experimentos/PageRank/out/exp1.time;
echo "S5000" >> experimentos/PageRank/out/exp1.time      
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s5000.in   experimentos/PageRank/out/exp1s5000.out; done; } 2>>   experimentos/PageRank/out/exp1.time;
echo "S10000" >> experimentos/PageRank/out/exp1.time    
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s10000.in  experimentos/PageRank/out/exp1s10000.out; done; } 2>>  experimentos/PageRank/out/exp1.time;
echo "S25000" >> experimentos/PageRank/out/exp1.time   
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s25000.in  experimentos/PageRank/out/exp1s25000.out; done; } 2>>  experimentos/PageRank/out/exp1.time;
echo "S50000" >> experimentos/PageRank/out/exp1.time  
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s50000.in  experimentos/PageRank/out/exp2s50000.out; done; } 2>>  experimentos/PageRank/out/exp1.time;
echo "S100000" >> experimentos/PageRank/out/exp1.time
{ time for i in {1..50} ; do ./main experimentos/PageRank/in/exp1s100000.in experimentos/PageRank/out/exp1s100000.out; done; } 2>> experimentos/PageRank/out/exp1.time;
