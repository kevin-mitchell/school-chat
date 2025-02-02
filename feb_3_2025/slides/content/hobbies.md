#### The most satisfying part of my job: making tools and websites that people find useful

<img src="/content/hobbies/first_website.png" height="500px" />

---

<!-- .element: data-background-image="/content/hobbies/mitchine.jpg" -->

My favorite thing about programming: using it for creativity and to build cool stuff
<!-- .element: style="background: rgba(255, 255, 255, 0.8); padding: 40px;" -->

---

**The best way I learn is by finding a way to apply what I am learning to a project I really care about.**

---

### Example: [breakfastcereal.tokyo](https://breakfastcereal.tokyo)

Learning about [Figma](https://www.figma.com/)
<!-- .element: style="font-size: 1.4rem;" -->

<div>
  <img
    class=""
    src="/content/hobbies/cereal_1.jpg"    
    height="500"
  />
  <img
    class=""
    src="/content/hobbies/cereal_2.jpg"    
    height="500"
  />
  <img
    class=""
    src="/content/hobbies/cereal_3.jpg"    
    height="500"
  />
  <img
    class=""
    src="/content/hobbies/cereal_4.jpg"    
    height="500"
  />
</div>

---

#### Example: 3D modeling, 3D printing, the internet!

Learning about working with Arduino _(make a gift for somebody!)_
<!-- .element: style="font-size: 1.4rem;" -->

<div class="r-stack">
    <img class="fragment fade-out" 
    data-fragment-index="0"
    height="500"
    src="/content/hobbies/mitchine_model.jpg" />
    <img    
    class="fragment current-visible"
    data-fragment-index="0"
    src="/content/hobbies/mitchine.gif"
  />
</div>

---

### Example: Electronics projects

Making it interesting to learn a new langauge (C)
<!-- .element: style="font-size: 1.4rem;" -->

<div class="r-stack">
    <img class="fragment fade-out" 
    data-fragment-index="0"
    height="500"
    src="/content/hobbies/house.webp" />        
    <img
    class="fragment current-visible"
    data-fragment-index="0"
    height="500"
    src="/content/hobbies/house_with_house.jpg" />
    <img
    class="fragment current-visible"
    data-fragment-index="1"
    height="500"
    src="/content/hobbies/smallest_website.jpg" />
    <img    
    class="fragment current-visible"
    data-fragment-index="2"
    height="500"
    src="/content/hobbies/marionette_pcb.jpg" />
    <img
    class="fragment current-visible"
    data-fragment-index="3"
    height="500"
    src="/content/hobbies/house_click.gif" />
</div>

---

#### Ask yourself...

> "What skills do I have that if used creatively will let me build something great?"
<!-- .element: style="background: rgba(210, 210, 210, 0.8); padding: 40px;" -->

Necessity is the mother of invention!

---

#### Example: When I only knew how to read a single button press

<div class="r-stack">
    <img class="fragment fade-out" 
    data-fragment-index="0"    
    src="/content/hobbies/morsel.gif" />
    <img    
    height="500"
    class="fragment current-visible"
    data-fragment-index="0"
    src="/content/hobbies/morsel_view.jpg"
  />
</div>

---

### Random links / thoughts

- [Learn markdown](https://www.markdowntutorial.com/) - useful for programming but also in Google docs / drive and many other places!
- [Ollama](https://ollama.com/) is a great way to experiment with AI for free in programming projects on your computer - read a bit about their [API](https://github.com/ollama/ollama/blob/main/docs/api.md) and checkout libraries for your favorite programming language (Python, JavaScript, etc)
- [Reveal.js](https://revealjs.com/) - the tool I used to make these slides
- Current trends in software development and programming in [the Stack Overflow Survey](https://survey.stackoverflow.co/2024/)
- Learn basics of web development and git (version control system) at the same time [and make a simple webpage on github](https://pages.github.com/)
- [Godot](https://docs.godotengine.org/en/stable/community/tutorials.html) is a good place to start if you want to learn about video game creation. It can be tough, but the tutorials section has some good learning resources, e.g. [this interactive tutorial!](https://gdquest.github.io/learn-gdscript)
- [Blender](https://www.blender.org/) - a free (though incredibly complicated!) and amazing tool for doing 3D modeling and rendering
- A bit of random history - [Steve Jobs announcing the first iPhone](https://www.youtube.com/watch?v=VQKMoT-6XSg)


<!-- .element: style="font-size: 1.6rem;" -->

---

# A tiny gift

Checkout [the github repository for more info `kevin-mitchell/school-chat`](https://github.com/kevin-mitchell/school-chat)

---

### Example: Checking the weather

```c++
  if (temp > 25) {
    // Hot!!!!
    leds[0] = CRGB::Red;
    FastLED.show();
  } else if (temp < 5) {
    // Cold!!!
    leds[0] = CRGB::LightSkyBlue;
    FastLED.show();
  } else if (rain > 0) {
    // Rain!!!!
    leds[0] = CRGB::Blue;
    FastLED.show();
    ...
```  