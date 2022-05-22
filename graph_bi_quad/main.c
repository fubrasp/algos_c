//s diviser ?
void BiQuad(int graph[N][N],int s) {

    // init step
    int i=0,u=0,k=0,q=0, neighbors[N],tmpN=-1;
    for (i = 0; i < N; i++) { dist[i] = -1;color[i]=0;pred[i]=-1;neighbors[i]=-1;}


    dist[s] = 0; color[s] = 1;
    enqueue(s);

    //is empty par rapport a G
    while(!isEmpty())
        //on dequeue dans G le vertex ?
        //on dequeue finalement les premiers vertex depuis le deput ?
        int v = dequeue();

        int count = 0,tmpN=-1;
        for(u=0;u<N;u++){
            // si on a un lien on travaille
            if(graph[v][u]==1){
                //si on a est pas déjà passé par la
                if(color[u] == 0){
                    //on colorise pour dire qu'on est deja passe
                    // finalement point de vue representation plus on dans un index u d'une colonne plus on est loin du v ?
                    //on met a plat les distances
                    //on note aussi les predesesseurs
                    color[u]=1; dist[u] = dist[v]+1; pred[u]=v;
                    enqueue(u);
                    // on a deux couleurs
                    }else if(color[u]==2 && dist[u]<=dist[v]){
                        neighbors[u]=1;
                        count=count + 1;
                        tmpN=u;
                    }
                }
            }

        //ca sert a rien de display un sous graph vide
        if(count>1){
            //double boucle pour aborder in fine toutes les combinaisons possibles
            for(u=0;u<N;u++){
                for(q=u+1;q<N;q++){
                    if(neighbors[u]==1 && neighbors[q]==1){
                        int fourthVertex = -1, distDiff = dist[q]-dist[u];
                            if(distDiff==0 || distDiff==1 || distDiff==-1){
                                if(graph[u][pred[q]]==1){
                                        fourthVertex = pred[q];
                                    }else if(graph[q][pred[u]]==1){
                                        fourthVertex = pred[u];
                                }
                            }
                    }
                        if(fourthVertex!=-1){
                            printf("BiQuad Subgraph: %d, %d, %d, %d\n",fourthVertex,q,v,u);
                            }
                        if(distDiff == 0){
                            for(k=0;k<N;k++){
                                if(k!=pred[q] && color[k]==2 && graph[q][k]==1 &&
                                      graph[u][k]==1){
                                    printf("BiQuad Subgraph: %d, %d, %d, %d\n",k,q,v,u);
                                    }
                                }
                            }
                        }
                    }
                neighbors[u]=-1;
                }

            Name: Matriculation number:
            }else if(count == 1){
            neighbors[tmpN] = -1;
            }
        color[v]=2;
        }