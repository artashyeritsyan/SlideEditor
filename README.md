# StrongDot
The program like PowerPoint, named similar "StrongDot" 

The Commands`
```
slide next - open next slide
slide prev - open previous slide
slide "index" - opens the slide with pageNumber == index

shapes - print all Shapes in current Slide
add shape -p (position (x, y) ) 

attributes`
-pos - "position" - x y
-s - "size" - width height
```


The Functions for Items and checks for them`
```
SendToBack(int index) - set the layerOrder = 0, and if it needed than increase the Orders all items by 1.
BringToTop(int index) - find the maximal value of layerOrder and set this item 1 one more than Max value.



```