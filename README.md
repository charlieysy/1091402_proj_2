# 1091402_proj_2

## 流程
StateDiagram[8] = { "SN ","WN1","WN2","WN3","WT3","WT2","WT1","ST " }; 
history初始值為000 
counter初始化為0
    1. 輸入測資 
    2. 輸出3-bit history(當前的前3個bits)，N:0,T:1 
    3. 輸出當前state狀態 
    4. 輸出當前指到的pattern
    5. 將history轉成二進位並判斷該位置是taken還是not taken，然後輸出 
       若目前是N，預測是T，則counter內該位置+1(移動到下一個StateDiagram)，若是N，則如果當前不為0(SN)，counter內該位置-1(回前一個StateDiagram)，並存起來(下一輪改變state狀態)。 
    6. 回到loop直到做完。
