//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{        printf("fac %d",fac(4));
        return 0;
}
int fac(int x)
{
 
  if(x==0)
   return 1;
   else
    return x*fac(x-1);
}
//---------------------------------------------------------------------------
 