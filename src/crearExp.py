#!/usr/bin/env python
import math
import numpy.random as npr
import random
import sys
import networkx as nx
import matplotlib.pyplot as plt

try:
    if(len(sys.argv) < 2):
        raise SystemError("Se debe dar al menos un parametro para indicar el modo de uso")
except SystemError as err:
    print(err.args)
    exit()

if (sys.argv[1] == "Hub"):
    try:
        if (len(sys.argv) != 9):
            raise SystemError("Parametros del modo Hub: <#hubs> <chance de linkear a un hub> <#nodos> <deg(i) minimo> <deg(i) maximo> <archivo de salida> <archivo .png del grafo>."
                                " Si no se desea dibujar el grafo, reemplazar la direccion del archivo por el string No")
    except SystemError as err:
        print(err.args)
        exit()

    hubs = int(sys.argv[2])
    hubsChance = float(sys.argv[3])
    n = int(sys.argv[4])
    min = int(sys.argv[5])
    max = int(sys.argv[6])
    out = open(sys.argv[7], "w")
    if (sys.argv[8] == "No"):
        seGrafica = False
    else:
        seGrafica = True
        outGraph = sys.argv[8]
    unifs = npr.random_integers(min, max, n)
    total = n + hubs
    totalRange = range(total)
    inRange = range(1, n + 1)
    hubsRange = range(n + 1, total + 1)
    j = 0

    out.write("# The woods are lovely, dark and deep\n")
    out.write("# But I have promises to keep\n")
    out.write("# Size: " + str(total) + ' And miles to go before I sleep\n')
    out.write("# And miles to go before I sleep\n")

    for i in inRange:
        perm = random.sample(inRange, unifs[i - 1])
        perm.sort()
        for j in range(len(perm)):
            outLine = str(i) + " " + str(perm[j]) + '\n'
            out.write(outLine)
        hubsVec = npr.binomial(1, hubsChance, hubs)
        for k in range(len(hubsVec)):
            if (hubsVec[k] == 1):
                outLine = str(i) + " " + str(k + n + 1) + '\n'
                out.write(outLine)
    for m in hubsRange:
        outVec = npr.binomial(1, hubsChance/len(hubsVec), total)
        for k in range(len(outVec)):
            if (outVec[k] == 1):
                outLine = str(m) + " " + str(k + 1) + '\n'
                out.write(outLine)
    out.close()

    if (seGrafica):
        edgeList = nx.read_edgelist (sys.argv[7], "#")
        graph = nx.DiGraph(edgeList)
        draw = nx.draw_networkx(
                        graph,
                        node_color = totalRange,
                        cmap = plt.cm.nipy_spectral,
                        edge_color = range(graph.number_of_edges()),
                        edge_cmap = plt.cm.rainbow,
                        node_size = 600 / math.sqrt(total), 
                        arrows = False, 
                        with_labels = False
                        )
        plt.axis("off")
        plt.savefig(outGraph)

elif (sys.argv[1] == "Ataque"):
    try:
        if (len(sys.argv) != 8):
            raise SystemError("Parametros del modo Ataque: <#nodos atacantes> <#nodos> <deg(i) minimo> <deg(i) maximo> <archivo de salida> <archivo .png del grafo>."
                                " Si no se desea dibujar el grafo, reemplazar la direccion del archivo por el string No")
    except SystemError as err:
        print(err.args)
        exit()
    atacantes = int(sys.argv[2])
    n = int(sys.argv[3])
    min = int(sys.argv[4])
    max = int(sys.argv[5])
    out = open(sys.argv[6], "w")
    if (sys.argv[7] == "No"):
        seGrafica = False
    else:
        seGrafica = True
        outGraph = sys.argv[7]
    unifs = npr.random_integers(min, max, n)
    inRange = range(1, n + 1)
    total = n + atacantes + 1
    attRange = range(n + 1, total)
    totalRange = range(1, total + 1)
    j = 0

    out.write("# The woods are lovely, dark and deep\n")
    out.write("# But I have promises to keep\n")
    out.write("# Size: " + str(total) + ' And miles to go before I sleep\n')
    out.write("# And miles to go before I sleep\n")

    for i in inRange:
        perm = random.sample(inRange, unifs[i - 1])
        perm.sort()
        for j in range(len(perm)):
            outLine = str(i) + " " + str(perm[j]) + '\n'
            out.write(outLine)

    for i in attRange:
        outLine = str(i) + " " + str(total) + '\n'
        out.write(outLine)

    outLine = str(total) + " " + str(total) + '\n'
    out.close()

    if (seGrafica):
        edgeList = nx.read_edgelist (sys.argv[6], "#")
        graph = nx.DiGraph(edgeList)
        draw = nx.draw_networkx(
                        graph,
                        node_color = totalRange,
                        cmap = plt.cm.nipy_spectral,
                        edge_color = range(graph.number_of_edges()),
                        edge_cmap = plt.cm.rainbow,
                        node_size = 600 / math.sqrt(total), 
                        arrows = False, 
                        with_labels = False
                        )
        plt.axis("off")
        plt.savefig(outGraph)


elif (sys.argv[1] == "Distribuido"):
    try:
        if (len(sys.argv) != 7):
            raise SystemError("Parametros del modo Distribuido: <#nodos> <deg(i) minimo> <deg(i) maximo> <archivo de salida> <archivo .png del grafo>."
                                " Si no se desea dibujar el grafo, reemplazar la direccion del archivo por el string No")
    except SystemError as err:
        print(err.args)
        exit()

    n = int(sys.argv[2])
    min = int(sys.argv[3])
    max = int(sys.argv[4])
    out = open(sys.argv[5], "w")
    if (sys.argv[6] == "No"):
        seGrafica = False
    else:
        seGrafica = True
        outGraph = sys.argv[6]
    unifs = npr.random_integers(min, max, n)
    inRange = range(1, n + 1)
    j = 0

    out.write("# The woods are lovely, dark and deep\n")
    out.write("# But I have promises to keep\n")
    out.write("# Size: " + str(n) + ' And miles to go before I sleep\n')
    out.write("# And miles to go before I sleep\n")

    for i in inRange:
        perm = random.sample(inRange, unifs[i - 1])
        perm.sort()
        for j in range(len(perm)):
            outLine = str(i) + " " + str(perm[j]) + '\n'
            out.write(outLine)
    out.close()

    if (seGrafica):
        edgeList = nx.read_edgelist (sys.argv[5], "#")
        graph = nx.DiGraph(edgeList)
        draw = nx.draw_networkx(
                        graph,
                        node_color = inRange,
                        cmap = plt.cm.nipy_spectral,
                        edge_color = range(graph.number_of_edges()),
                        edge_cmap = plt.cm.rainbow,
                        node_size = 600 / math.sqrt(n), 
                        arrows = False, 
                        with_labels = False
                        )
        plt.axis("off")
        plt.savefig(outGraph)

else:
    try:
        raise SystemError("Los modos posibles son: Distribuido , Ataque.")

    except SystemError as err:
        print(err)
