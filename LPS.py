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
patr = input()
print(lps(patr))
