// Hari

int compareVersion(string v1, string v2) {
        int i = 0, j = 0, len1 = v1.size(), len2 = v2.size();
        while(i < len1 || j < len2){
            unsigned long num1 = 0, num2 = 0;
            while(i < len1 && v1[i] != '.') {
                num1 = num1*10 + (v1[i] - '0'); i++;
            }
            while(j < len2 && v2[j] != '.') {
                num2 = num2*10 + (v2[j] - '0'); j++;
            }
            
            // compare numbers till this .
            //if(num1 != num2)    return num1 < num2 ? -1 : 1; // also works
            if(num1 < num2) return -1;
            if(num1 > num2) return 1;
            // if both equal
            i++; j++;
        }
        return 0;
    }
