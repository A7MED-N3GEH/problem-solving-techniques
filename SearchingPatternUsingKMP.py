# ( إِنَّ اللَّهَ وَمَلَائِكَتَهُ يُصَلُّونَ عَلَى النَّبِيِّ ۚ يَا أَيُّهَا الَّذِينَ آمَنُوا صَلُّوا عَلَيْهِ وَسَلِّمُوا تَسْلِيمًا ) 
def lps(pat):
    a_lps = [0] * len(pat)
    i,j = 0 , 1
    while j < len(pat):
        if pat[i] == pat[j]:
            i+=1
            a_lps[j] = i
            j+=1
        else:
            if i!=0:
                i = a_lps[i-1]
            else:
                a_lps[j] = 0
                j+=1
            
    return a_lps
def search(s,patr):
    n,m = len(s),len(patr)
    i,j = 0,0
    arr_lps = lps(patr)
    ans = []
    while i<n:
        if s[i] == patr[j]:
            i+=1
            j+=1
            if j == m:
                ans.append(i-j)
                j = arr_lps[j-1]
        else:
            if j != 0:
                j = arr_lps[j - 1]
            else:
                i+=1
    return ans
s = input()
patr = input()
print(*search(s,patr))
