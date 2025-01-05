    #include "input.h"
    #include "maquinas.h"

    void lerID_Mq(int *id)
    {
        lerInt(MAX_ID_MQ , MIN_ID_MQ , id , MSG_ID_MQ);
    }
    void lerNome_Mq(char *nome)
    {
        lerString(MAX_NOME_MQ , nome , MSG_NOME_MQ);
    }
    void lerTipo_Mq(Tipo *t)
    {
        lerInt(MAX_TIPO , MIN_TIPO , (int*)t , MSG_TIPO);
    }

    int Id_MqToInt(Maquinas maquinas , int id_Mq)
    {
        int index;
        for(int i = 0 ; i < maquinas.contador; i++)
        {
            if(maquinas.array[i].id_Mq == id_Mq)
            {
                index = i;
            }
        }

        return index;
    }
    bool Id_Mq_Existe(Maquinas maquinas , int id_Mq)
    {
        bool existe = false;
        for(int i = 0 ; i < maquinas.contador ; i++)
        {
            if(id_Mq == maquinas.array[i].id_Mq)
            {
                existe = true;
            }
        }

        return existe;
    }
    void trocaMaquinas(Maquina *a , Maquina *b)
    {
        Maquina temp;
        *a = *b;
        *b = temp;
    }


    char* devolveTipo(Tipo t)
    {
        switch (t)
        {
        case TIPO_NAOATRIBUIDO:
            return "___NAO ATRIBUIDO__";
            break;

        case TIPO_CORTE:
            return "Corte";
            break;

        case TIPO_INJECAO:
            return "Injeção";
            break;

        case TIPO_SOLDA:
            return "Solda";
            break;  

        case TIPO_FRESAGEM:
            return "Fresagem";
            break;

        case TIPO_LIXAMENTO:
            return "Lixamento";
            break;

        case TIPO_PERFURACAO:
            return "Perfuração";
            break;
        
        case TIPO_CNC:
            return "CNC";
            break;

        case TIPO_TORNEAMENTO:
            return "Torneamento";
            break;

        case TIPO_IMPRESSAO:
            return "Impressão";
            break;

        case TIPO_EMBALAGEM:
            return "Embalagem";
            break;
        }
    }

    void ordenarporId_Mq(Maquinas *maquinas)
    {
        for(int i = 0; i < maquinas->contador - 1; i++)
        {
            for(int j = 0 ; j < maquinas->contador - i - 1 ; j++)
            {
                if(maquinas->array[j].id_Mq > maquinas->array[j + 1].id_Mq)
                {
                    trocaMaquinas(&maquinas->array[j] , &maquinas->array[j + 1]);
                }
            }
        }
    }
    void imprimirporTipo(Maquinas maquinas)
    {

        printf("                 ||  ID   ||            Maquina             ||\n");
        printf("--------------------------------------------------------------\n");


         for(Tipo t = MIN_TIPO; t <= MAX_TIPO; t++)
         {
            int counter = 0;

            for(int i = 0; i < maquinas.contador ; i++)
            {
                if(maquinas.array[i].t_Mq == t)
                {
                    if(counter == 0)
                    {
                        printf("\nTipo: %s\n" , devolveTipo(t));
                    }

                    printf(".                    %-4d || %-30s \n", 
                       maquinas.array[i].id_Mq, 
                       maquinas.array[i].nome_Mq);

                    counter++;
                }
            }

            if(counter > 0)
            {
                printf("Total Maquinas: %d\n" , counter);
            }
         }    
    }
    void imprimirsemserporTipo(Maquinas maquinas)
    {
        printf("ID   ||            Maquina             ||    Tipo    \n");
        printf("----------------------------------------------------- \n");
        for (int i = 0; i < maquinas.contador; i++)
        {
            printf("%-4d || %-30s || %-15s \n",
                maquinas.array[i].id_Mq,
                maquinas.array[i].nome_Mq,
                devolveTipo(maquinas.array[i].t_Mq) );
        }
    }

    void listarMaquinas(Maquinas maquinas)
    {
        int ans;
        lerInt(2 , 1 , &ans ,"Como deseja ordenar a listagem?:\n1.Por Id\n2.Por Tipo\n.");

        switch (ans)
        {
            case 1:
                ordenarporId_Mq(&maquinas);
                imprimirsemserporTipo(maquinas);
                break;
            case 2:
                imprimirporTipo(maquinas);
                break;    
        }
    }
    void createMaquina(Maquinas *maquinas)  
    {
        if(maquinas->contador >= 100)
        {
            puts(MACHINES_SCT_FULL_ERRMSG);
        }
        else
        {
            do
            { 
                lerID_Mq(&maquinas->array[maquinas->contador].id_Mq);
                if(Id_Mq_Existe(*maquinas , maquinas->array[maquinas->contador].id_Mq) == true)
                {
                    puts(ALREADYEXISTENT_ID_ERRORMSG);
                }
            } while (Id_Mq_Existe(*maquinas , maquinas->array[maquinas->contador].id_Mq) == true);
            
            lerNome_Mq(maquinas->array[maquinas->contador].nome_Mq);
            lerTipo_Mq(&maquinas->array[maquinas->contador].t_Mq);


            maquinas->contador++;
        }
    }
    void readMaquina(Maquinas maquinas)
    {
        int id_Mq;
        if(maquinas.contador > 0)
        {
            do
            {
                lerID_Mq(&id_Mq);

                if( Id_Mq_Existe(maquinas, id_Mq) == false)
                {
                    puts(NONEXISTENT_ID_ERRORMSG);
                }

            } while (Id_Mq_Existe(maquinas , id_Mq) == false);

            int i = Id_MqToInt(maquinas , id_Mq);

            printf("ID: %d" , maquinas.array[i].id_Mq);
            printf("\t\tNome: %s" , maquinas.array[i].nome_Mq);
            printf("\t\tTipo: %s" , devolveTipo(maquinas.array[i].t_Mq));
        }
        else
        {
            puts(MACHINES_SCT_EMPTY_ERRMSG);
        }
    }
    void updateMaquina(Maquinas *maquinas)
    {
        int id_Mq;
        if(maquinas->contador > 0)
        {
            do
            {
                lerID_Mq(&id_Mq);

                 if( Id_Mq_Existe(*maquinas, id_Mq) == false)
                {
                    puts(NONEXISTENT_ID_ERRORMSG);
                }

            } while (Id_Mq_Existe(*maquinas , id_Mq) == false);

            int i = Id_MqToInt(*maquinas , id_Mq);
            do
            {
                int ans;
                lerInt(3 , 0 , &ans , "O que deseja alterar?\n\n1.Id\n2.Nome\n3.Tipo\n0.Sair\n.");
                
                if(ans > 0)
                {
                    switch (ans)
                    {
                        case 1:
                            lerID_Mq(&maquinas->array[i].id_Mq);
                            break;
                        case 2:
                            lerNome_Mq(maquinas->array[i].nome_Mq);
                            break;
                        case 3:
                            lerTipo_Mq(&maquinas->array[i].t_Mq);
                            break;
                        default:
                            break;
                    }
                }else
                {
                    break;
                }
            } while (true);
            
            
        }
        else
        {
            puts(MACHINES_SCT_EMPTY_ERRMSG);
        }
    }
    void deleteMaquina(Maquinas *maquinas)
    {
        int id_Mq;

        do
        {
            lerID_Mq(&id_Mq);

            if( Id_Mq_Existe(*maquinas, id_Mq) == false)
            {
                puts(NONEXISTENT_ID_ERRORMSG);
            }

        } while (Id_Mq_Existe(*maquinas , id_Mq) == false);
        
        int i = Id_MqToInt(*maquinas , id_Mq);

        maquinas->array[i].id_Mq = 0;
        strcpy(maquinas->array[i].nome_Mq , "___NÃO ATRIBUIDO___");
        maquinas->array[i].t_Mq = -1;

        for( ; i < maquinas->contador ; i++)
        {
            trocaMaquinas(&maquinas->array[i] , &maquinas->array[i + 1]);
        }

        maquinas->contador--;
    }

    void CRUD_Maquinas(Maquinas maquinas)
    {
        do
        {
            int ans;
            printf("1.Criar Maquina\n2.Ler Maquina\n3.Atualizar Maquina\n4.Eliminar Maquina\n5.Listar Maquina\n0.Sair\n");
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
                        createMaquina(&maquinas);
                        break;
                    case 2:
                        readMaquina(maquinas);
                        break;
                    case 3:
                        updateMaquina(&maquinas);
                        break;
                    case 4:
                        deleteMaquina(&maquinas);
                        break;
                    case 5:
                        listarMaquinas(maquinas);
                        break;
                }
            }

            for(int i = 0 ; i < 5 ; i++)
            {
                printf(".\n");
            }
        } while (true);
        
    } 