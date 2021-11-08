f = open(indexName,"rb")
f.seek(0, 2)
inicio = 0
fim = (f.tell()/indexStruct.size) - 1
contador = 0
i=0
while(inicio <= fim):
    linha = f.read(indexStruct.size)
    if not linha: #Não há nada na linha (posição do indice)
        contador+=1
    i+=1
    f.seek(indexStruct.size)
f.close()