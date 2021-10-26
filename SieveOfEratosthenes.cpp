const long long int MAX_N = 1e6 + 7;
vector<int> prime;
vector<int> _prime;
vector<int> factor;
void sieve()
{
    factor.resize(MAX_N , 0);
    prime.resize(MAX_N , 0);
    prime[1]=1;
    prime[2]=0;
    for(int32_t i = 2 ; i<MAX_N ; i++)
    {
        if(!prime[i])
            {
                _prime.pb(i);
                factor[i] = i;
                for(int32_t j= i*i ; j<MAX_N ; j+=i)
                {
                    prime[j]=1;
                    factor[j] = i;
                }
            }
    }
}
