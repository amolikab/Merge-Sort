
def Compare(list,f,m,b):
    if (list[f]>list[m]>list[b])|(list[b]>list[m]>list[f]):
        #print "median is at position %d " %m;
        return m;
    elif(list[m]>list[b]>list[f])|(list[f]>list[b]>list[m]):
        #print "median is at position %d " %b;
        return b;
    else:
        #print "median is at position %d " %f;
        return f;       


def ChoosePivot(list,f,b):
    n = b-f+1;
    if(n>=3):
        if n%2 == 0 :
            #print "even number list";
            m = f+((n/2)-1);
            #print "compare: %d : %d : %d" %(list[f],list[m],list[b]);
            return (Compare(list,f,m,b));        
        else:
            #print "odd number list";
            m = f+((n-1)/2);
            #print "compare: %d : %d : %d" %(list[f],list[m],list[b]);
            return (Compare(list,f,m,b));  
    else:
        return f; 

#    return list[b];
      
def display(list,f,b):
    #n = b-f+1;
    while(f<=b):
        print "%d" %list[f];
        f=f+1;

      
def quick(list,f,b):
    if (f > b):
        return;
    else:
        #display(list,f,b);
        pos = ChoosePivot(list,f,b);
        p = list[pos];
        print "pivot is %d" %list[pos];
        list[f],list[pos] = list[pos],list[f];
        x = b-f;
        #print "length of array is : %d\n" %(x+1);
        count[0] = count[0] + x;
        #print (count[0]);
        #print "The pivot is %d" %p;
        #print "position of pivot is %d" %f;
        #print (list);
        #print "\n";
        i =f+1;
        j=f+1;
        #print "value of f : %d\n" %f;
        #print"value of b : %d\n" %b;
        #print "value of i : %d\n" %i;
        #print"value of j : %d\n" %j;
        while(j<=b):
            if(list[j]<p):
                #print "swapping %d and %d" %(list[i],list[j] );
                list[i],list[j] = list[j],list[i];
                j=j+1;
                i = i+1;  
                #print "value of i : %d\n" %i;
                #print"value of j : %d\n" %j;
                #print "list after swap\n";
                #print (list);                        
            elif list[j]>p:
                j = j+1;
                #print "value of i : %d\n" %i;
                #print"value of j : %d\n" %j;
        #print "placing pivot in place";
        list[i-1],list[f] = list[f],list[i-1]; 
        #print(list);           
        #print "new pivot is at list[%d]" %(i-1);
        quick(list,f,i-2);
        quick(list,i,b);



        
file = open("QuickSort.txt","r");
#line = file.readlines();
list = [4,2,5,3,9,6,8,1,15,96,36,45,87,79,19,11,859,654,235,784,5986];
#print (list);
A=[];
count = [0];
A=[int(line) for line in file.read().split() ];
#A.append([int(x) for x in line.split()]);
#print (type(A));
#print (A);
n=len(A);
print " number : %d" %n;
quick(A,0,n-1);
#print (A);
print (count[0]);

#p = Pivot(A,0,n-1);
#print "median is : %d" %A[p];
file.close();










