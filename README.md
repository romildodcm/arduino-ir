# In Development...


## APPLICATIONS

### A Base for Line Follower or Color Detector

![Alt Text](./img/parallel.jpg)

With the infrared LED beside the phototransistor we can, for example, detect colors by the difference between the absorption/reflection of infrared, another application is with an array of these pairs to make a line follower for robots. In the following graph, it's possible to see the difference in the signal received by varying colors/materials in front of the emitter and receiver with the [code for analog read and moving average filter](./codes/ir_filtered).

Figure 1 - Difference in the signal received by varying colors/materials.
![Figure 1 - Difference in the signal received by varying colors/materials](./data_samples/parallel_ir_filtered_graph.png)

In Figure 1, from the left to the right, it's possible to see that the signal down near 850 bits when I put a gray object in the front of the sensor, the big down of the signal to near 650 has occurred when I put a white object, for black object the signal down from 970/960 to near 950/940, this occurs because white reflects more than gray, which reflects more than black.

![](./img/parallel_all.jpg)

## REFERENCES

[1] Como usar com Arduino – Led Emissor IR e Fototransistor IR <https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-led-emissor-ir-e-fototransistor-ir/>
[2] Arduino + Filtros: Média Móvel <https://youtu.be/AEsAxho1Y-Y>








### Anotações dos teste

FUNCIONOU BEM E com diferença de aproximadamente 100 bits entre o sinal com ir e com o ir interrompido, isso com 200mm de distância entre o emissor e o receptor, se diminuir a distânica, aquele valor de diferença que é de 100 bits só vai aumentando.