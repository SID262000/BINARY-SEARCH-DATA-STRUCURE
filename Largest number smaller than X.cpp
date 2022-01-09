int indx = lower_bound(a,a+n,X)-a;
indx--;

if(indx>=0) cout<< a[indx];
else cout<<-1;