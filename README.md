# height_map_topography

This code helps compute grayscaled height maps images showing the highest parts horizontally and vertically.

### EXAMPLE 1

<p>
  <img src="https://github.com/the-kim-jong-un/height_map_topography/blob/main/data/shape.png" width="255" height="255">
  <img src="https://github.com/the-kim-jong-un/height_map_topography/blob/main/data/shape_leftRight.png" width="255" height="255">
  <img src="https://github.com/the-kim-jong-un/height_map_topography/blob/main/data/shape_topBottom.png" width="255" height="255">
</p>

<br>

### EXAMPLE 2

<p>
  <img src="https://github.com/the-kim-jong-un/height_map_topography/blob/main/data/river.png" width="256" height="256">
  <img src="https://github.com/the-kim-jong-un/height_map_topography/blob/main/data/river_leftRight.png" width="255" height="255">
  <img src="https://github.com/the-kim-jong-un/height_map_topography/blob/main/data/river_topBottom.png" width="255" height="255">
</p>


### How to use
At the root of the project type :
```makefile
make 
/bin/main image_path save_path
```

-**image_path** : is the path to your image like "data/img/yourImage.png" <br>
-**save_path**  : is the path where you'd like to save your image like  : "data/savedImages/" <br>
-In this exmple the images are going to be renamed "**yourImage_leftRight.png**" and "**yourImage_topBottom.png**"<br>
-The variable **timeWindowON** in the .h sets the time the windows displaying the results stays open (in milliseconds).<br>
-You can choose not to display the results by commenting the **display()** function in the .cpp <br>

**Works for .png/.jpg/.jpeg**

### Dependencies 
This code uses the OPENCV (C++) library.
