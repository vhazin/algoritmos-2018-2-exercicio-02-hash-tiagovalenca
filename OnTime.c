/*
 * Hash problem sample solution, optimization of the code done by Otacilio Maia
 *  Tiago Lopes Valença
 */
 #include <stdio.h>

typedef long long ll;

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })

#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

#define mod(a, b) (a - ((a / b) * b))

ll res(ll partial, ll d, ll n, ll m, ll L, char flag);
ll counter;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll a, b, x, n, c, d, m;
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &x, &n, &c, &d, &m);

        if(a==0 && b==0 && c==0){
          counter = n + 1;
          printf("%llu\n", counter);
          counter = 0;
        }else if(a*x+b>=c && a+x+b<=d && m>=d && a*x+b<m && m>n && n>=d){
          counter = d-c+1;
          printf("%llu\n", counter);
          counter = 0;
        }else{
          ll partial = (a * x + b) % m;

          ll ans = res(partial, a, n, m, d + 1, 0) - res(partial, a, n, m, c, 0);

          printf("%lld\n", ans);
        }
    }
    return 0;
}

ll res(ll partial, ll d, ll n, ll m, ll L, char flag)
{
    if (L == 0)
        return 0;
    if (m == 1 || L >= m)
        return n + 1;
    if (d == 0 || n == 0)
        return ((flag) ? (!partial || partial >= m - L + 1) : (partial <= L - 1)) * (n + 1);

    ll k = 0;
    if (flag)
    {
        k = (!partial) + (partial + n * d + m - 1) / m;
    }
    else
    {
        k = (partial + n * d) / m + 1;
    }

    ll f1 = 0, fk = 0;
    if (flag)
    {
        if (partial == 0)
        {
            f1 = 1;
        }
        else
        {
            ll x1 = max((m - L + 1 - partial + d - 1) / d, 0ll);
            ll x2 = min((m - partial) / d, n);
            f1 = max(x2 - x1 + 1, 0ll);
        }

        if (k >= 2)
        {
            ll high = (partial + n * d + m - 1) / m * m;
            ll c = max((high - L + 1 - partial + d - 1) / d, 0ll);
            fk = max(n - c + 1, 0ll);
        }
    }
    else
    {
        if (partial <= L - 1)
            f1 = min((L - 1 - partial) / d, n) + 1;

        if (k >= 2)
        {
            ll high2 = (partial + n * d) / m * m;
            ll c1 = (high2 - partial + d - 1) / d;
            ll c2 = min((high2 + L - 1 - partial) / d, n);
            fk = max(c2 - c1 + 1, 0ll);
        }
    }

    if (k <= 2)
        return f1 + fk;
    if (d == 1)
        return f1 + fk + L * (k - 2);

    ll nL = mod(L, d), nd = mod(m, d), nm = d, nn = k - 3, q = 0;
    if (flag)
    {
        ll nu;
        if (partial)
        {
            nu = partial + (2 * m - partial) / d * d;
        }
        else
        {
            nu = partial + (m - partial) / d * d;
        }
        nu = mod(nu, m);

        if (nu == 0)
            nu = m;
        nu = m - nu;

        if (nd <= d / 2)
        {
            q = res(nu - ((nu / d) * d), nd, nn, nm, nL, 0);
        }
        else
        {
            q = res((d - (nu - ((nu / d) * d))), d - nd, nn, nm, nL, 1);
        }
    }
    else
    {
        ll nu = partial + (m - partial + d - 1) / d * d;
        nu = mod(nu, m);

        if (d - nd <= d / 2)
        {
            q = res(nu - ((nu / d) * d), d - nd, nn, nm, nL, 0);
        }
        else
        {
            q = res((d - (nu - ((nu / d) * d))), nd, nn, nm, nL, 1);
        }
    }

    return f1 + fk + (L / d) * (k - 2) + q;
}
