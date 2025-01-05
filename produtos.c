    #include "input.h"
    #include "produtos.h"  
    #include "maquinas.h"

    void lerID(int *ID)
    {
        lerInt(MAX_ID , MIN_ID , ID , MSG_ID);
    }
    void lerNome(char *nome)
    {
        lerString(MAX_NOME , nome , MSG_NOME);
    }
    void lerCategoria(Categoria *c)
    {   

          lerInt(MAX_CATEGORIA , MIN_CATEGORIA   , (int *)c , MSG_CATEGORIA);
    }
    void lerProcura(Procura *p)
    {
         lerInt(MAX_PROCURA  , MIN_PROCURA ,(int *) p , MSG_PROCURA);
    }
    void lerTempo(int *tempo)
    {
        //1segundo equivale a 10mins;

        lerInt(240 , 1 , tempo , "Introduza o tempo que o processo demora(em mins): "); //1seg = 1min
        *tempo /= 10;                                                                   //1seg = 10min
    }
    void lerProcessos(Processos *processos , Maquinas maquinas)
    {
        
        if(processos->contador < 5)
        {
            do
            {
                char ans;
                
                lerChars( 's' , 'n' , &ans , "Deseja Acrescentar um processo?(s-sim/n-não): ");
                imprimirsemserporTipo(maquinas);
                if(ans == 's')
                {

                    do
                    {
                        lerID_Mq(&processos->array[processos->contador].idMaq);

                        if (Id_Mq_Existe(maquinas , processos->array[processos->contador].idMaq) == false)
                        {
                            puts(NONEXISTENT_ID_ERRORMSG);
                        }
                        
                    } while (Id_Mq_Existe(maquinas , processos->array[processos->contador].idMaq) == false);
                    
                    lerTempo(&processos->array[processos->contador].tempo);

                    processos->contador++;
                
                }
                if(ans == 'n')
                {
                    break;
                }
            } while (true);
        }
    }
    int IDtoInt(Produtos produtos , int ID)        //retorna o indice da array (onde o produto se encontra na array) usando o id do produto
    {
        int index;

        for(int i = 0 ; i < produtos.contador; i++)
        {
            if(produtos.array[i].ID == ID)
            {
                index = i;
            }
        }

        return index;
    }
    bool ID_Existe(Produtos *produtos , int ID)
    {
        bool existe = false;

        for(int i = 0 ; i < produtos->contador ; i++)
        {
            if(produtos->array[i].ID == ID)
            {
                existe = true;
            }
        }

        return existe;
    }
    void trocaProdutos(Produto *a , Produto *b)
    {

        Produto temp = *a;
        *a = *b;
        *b = temp;
    }

    char* devolveCategoria(Categoria c)
    {
        switch (c)
        {
            case CATEGOIRIA_NAOATRIBUIDO:
                return "___NAO ATRIBUIDO___";
                break;
            case CATEGORIA_SENSOR:
                return "Sensor";

            case CATEGORIA_CABO:
                return "Cabo";
            
            case CATEGORIA_PLACA_PROTOTIPO:
                return "Placa Protótipo";

            case CATEGORIA_COMPONENTE:
                return "Componente";

            case CATEGORIA_DISPLAY:
                return "Display";

            case CATEGORIA_MOTOR:
                return "Motor";

            case CATEGORIA_SHIELD:
                return "Shield";

            default:
                break;
        }
    }
    char* devolveProcura(Procura p)
    {
        switch (p)
        {
            case PROCURA_NAOATRIBUIDO:
                return "__NAO ATRIBUIDO__";
                break;

            case PROCURA_ALTA:
                return "Alta";
                break;

            case PROCURA_MEDIA:
                return "Media";
                break;

            case PROCURA_BAIXA:
                return "Baixa";
                break;
            default:
                break;
        }
    }

    void ordenarporID(Produtos *produtos)
    {
        for(int i = 0 ; i < produtos->contador - 1; i++)
        {
            for(int j = 0 ; j < produtos->contador - i - 1 ; j++)
            {
                if(produtos->array[j].ID > produtos->array[j+1].ID)
                {
                    trocaProdutos(&produtos->array[j] , &produtos->array[j + 1]);
                }
            }
        } 
    }
    void ordenarporOrdemAlfabetica(Produtos *produtos)
    {
        for(int i = 0 ; i < produtos->contador - 1; i++)
        {
            for(int j = 0 ; j < produtos->contador - i - 1; j++)
            {
                if(strcmp(produtos->array[j].nome , produtos->array[j + 1].nome) > 0)
                {
                    trocaProdutos(&produtos->array[j] , &produtos->array[j + 1]);
                }
            }
        }
    }   
    void ordenarporProcura(Produtos *produtos)
    {
        for(int i = 0 ; i < produtos->contador - 1; i++)
        {
            for(int j = 0 ; j < produtos->contador - i - 1; j++)
            {
                if(produtos->array[j].p < produtos->array[j + 1].p)
                {
                    trocaProdutos(&produtos->array[j] , &produtos->array[j + 1]);
                }
            }
        }
    }
    void imprimirporCategoria(Produtos produtos)
{
     
    printf("                 ||  ID   ||            Produto             || Procura\n");
    printf("-------------------------------------------------------------------------------\n");

    
    for (Categoria i = MIN_CATEGORIA; i <= MAX_CATEGORIA; i++)
    {
        int counter = 0;

         
        for (int j = 0; j < produtos.contador; j++)
        {
            if (produtos.array[j].c == i)
            {
                if (counter == 0)
                {
                     
                    printf("\nCategoria: %s\n", devolveCategoria(i));
                }

                 
                printf(".                    %-4d || %-30s || %-10s\n", 
                       produtos.array[j].ID, 
                       produtos.array[j].nome, 
                       devolveProcura(produtos.array[j].p));
                counter++;
            }
        }
         
        if (counter > 0)
        {
            printf("Total Produtos: %d\n", counter);
        }
    }
}
    void imprimirsemserporCategoria(Produtos produtos)
    {
        printf("ID   ||            Produto             ||    Categoria    || Procura\n");
        printf("-------------------------------------------------------------------------------\n");
        for (int i = 0; i < produtos.contador; i++)
        {
            printf("%-4d || %-30s || %-15s || %-10s\n",
                produtos.array[i].ID,
                produtos.array[i].nome,
                devolveCategoria(produtos.array[i].c),
                devolveProcura(produtos.array[i].p));
        }
    }

    void listarProdutos(Produtos produtos)
    {
        int ans;
        lerInt(4 , 1 , &ans ,"Como deseja ordenar a lista?:\n1.Por ID\n2.Por Ordem Alfabética\n3.Por Procura\n4.Por Categoria\n." );
        switch(ans)
        {
            case 1:
                ordenarporID(&produtos);
                imprimirsemserporCategoria(produtos);
                break;
            case 2:
                ordenarporOrdemAlfabetica(&produtos);
                imprimirsemserporCategoria(produtos);
                break;
            case 3:
                ordenarporProcura(&produtos);
                imprimirsemserporCategoria(produtos);
                break;
            case 4:
                imprimirporCategoria(produtos);
        } 

    }
    void createProduto(Produtos *produtos , Maquinas maquinas)
    {


        if(produtos->contador >= 100)
        {
            puts(PRODUCTS_SCT_FULL_ERRMSG);
        }
        else
        {
            do
            {
                lerID(&produtos->array[produtos->contador].ID);

                if(ID_Existe(produtos , produtos->array[produtos->contador].ID) == true)
                {
                    puts(ALREADYEXISTENT_ID_ERRORMSG);
                }
            } while (ID_Existe(produtos , produtos->array[produtos->contador].ID) == true);
            
            lerNome(produtos->array[produtos->contador].nome);
            lerCategoria(&produtos->array[produtos->contador].c);
            lerProcura(&produtos->array[produtos->contador].p);
            lerProcessos(&produtos->array[produtos->contador].Processos , maquinas);
        }

        produtos->contador++;
        clearConsole;
    }
    void readProduto(Produtos produtos)
    {
        int id;
        if(produtos.contador > 0)
        {
            do
            {
                lerID(&id);
                if(ID_Existe(&produtos, id) == false)
                {
                    puts(NONEXISTENT_ID_ERRORMSG);
                }

            } while (ID_Existe(&produtos , id) == false);
            clearConsole;

            

            printf("ID: %d" , produtos.array[IDtoInt(produtos , id)].ID);
            printf("\t\tNome: %s" , produtos.array[IDtoInt(produtos , id)].nome);
            printf("\tCategoria: %s",devolveCategoria(produtos.array[IDtoInt(produtos , id)].c));
            printf("\tProcura: %s\n",devolveProcura(produtos.array[IDtoInt(produtos , id)].p));  
        }
        else
        {
            printf(PRODUCTS_SCT_EMPTY_ERRMSG);
        }
        
        
    }
    void updateProduto(Produtos *produtos)
    {
        int id;
        if(produtos->contador > 0)
        {
            do
            {
                lerID(&id);
                if(ID_Existe(produtos, id) == false)
                {
                    puts(NONEXISTENT_ID_ERRORMSG);
                }

            } while (ID_Existe(produtos , id) == false);

            int i = IDtoInt(*produtos , id);    

            do
            {
                int ans;
                lerInt(4 , 0 , &ans , "\nO que deseja alterar?\n\n1.ID\n2.Nome\n3.Categoria\n4.Procura\n0.Sair\n");

                if(ans > 0)
                {
                    switch (ans)
                    {
                        case 1:
                            lerID(&produtos->array[i].ID);
                            break;
                        
                        case 2:
                            lerNome(produtos->array[i].nome);
                            break;
                        case 3:
                            lerCategoria(&produtos->array[i].c);
                            break;

                        case 4:
                            lerProcura(&produtos->array[i].p);
                            break;

                        default:
                            break; 
                    }
                    clearConsole;
                }
                else
                {
                    break;
                }

            } while (true);
            clearConsole;
        }
        else
        {
            printf(PRODUCTS_SCT_EMPTY_ERRMSG);
        }
    } 
    void deleteProduto(Produtos *produtos)
    {
        int id;

        do
        {
            lerID(&id);
            if(ID_Existe(produtos , id) == false)
            {
                printf(NONEXISTENT_ID_ERRORMSG);
            }
        } while (ID_Existe(produtos , id) == false);
        
        int i = IDtoInt(*produtos , id);

        produtos->array[i].ID = 0;
        strcpy(produtos->array[i].nome , "___NÃO ATRIBUIDO___");
        produtos->array[i].c = -1;
        produtos->array[i].p = -1;

        for( ; i < produtos->contador ; i++)
        {
            produtos->array[i].ID = produtos->array[i + 1].ID;
            strcpy(produtos->array[i].nome , produtos->array[i + 1].nome);
            produtos->array[i].c = produtos->array[i + 1].c;
            produtos->array[i].p = produtos->array[i + 1].p;
        }

        produtos->contador--;


    }
    
    void CRUD_Produtos(Produtos produtos , Maquinas maquinas)
    {
        do
        {
            int ans;
            printf("1.Criar Produto\n2.Ler Produto\n3.Atualizar Produto\n4.Eliminar Produto\n5.Listar Produtos\n0.Sair\n");
            lerInt(5 , 0 , &ans , ". ");
            clearConsole;
            if(ans == 0)
            {
                break;
            }
            else
            {
                switch (ans)
                {
                case 1:
                    createProduto(&produtos , maquinas);
                    break;
                case 2:
                    readProduto(produtos);
                    break;
                case 3:
                    updateProduto(&produtos);
                    break;
                case 4:
                    deleteProduto(&produtos);
                    break;
                case 5:
                    listarProdutos(produtos);
                }
            }
            for(int i = 0; i < 5; i++)
            {
                printf(".\n");
            }
        } while (true);
    }