% clear

f = fopen('rice.raw','r');

Imagedata = fread(f,690*500*3,'uint8=>uint8');

j=1;

for i=1:3:(690*500*3)-2

    Red(j)=Imagedata(i);

    j=j+1;

end

k=1;

for i=2:3:(690*500*3)-1

    Green(k)=Imagedata(i);

    k=k+1;

end

l=1;

for i=3:3:(690*500*3)

    Blue(l)=Imagedata(i);

    l=l+1;

end

 

img_red = reshape(Red,690,500)';

img_green = reshape(Green,690,500)';

img_blue = reshape(Blue,690,500)';

 

 

rice_img(:,:,1)=img_red(:,:);

rice_img(:,:,2)=img_green(:,:);

rice_img(:,:,3)=img_blue(:,:);

 

figure

imshow(rice_img)

grayscale = rgb2gray(rice_img);

edge1 = edge(grayscale,'canny', 0.1);
figure;
imshow(edge1)


% Extract target regions
str1 = strel('line', 2, 90);
str2 = strel('line', 2, 0);
dilate = imdilate(edge1,[str1 str2]);
figure;
imshow(dilate)
fill = imfill(dilate,'holes');
imshow(fill)
str3 = strel('diamond',4);
erode = imerode(fill,str3);
figure;
imshow(erode)

% Measure the statistics
measure = regionprops(erode,{'Area','Centroid'});
measure = struct2table(measure);

% Show the result
figure;
imshow(rice_img)
hold on
for kk = 1:height(measure)
  text(measure.Centroid(kk,1)+10, measure.Centroid(kk,2),...
      num2str(measure.Area(kk)))
end
index=ones(11);
cluster1=zeros(5);
cluster2=zeros(5);
cluster3=zeros(5);
cluster4=zeros(5);
cluster5=zeros(5);
cluster6=zeros(5);
cluster7=zeros(5);
cluster8=zeros(5);
cluster9=zeros(5);
cluster10=zeros(5);
cluster11=zeros(5);

for i = 1:height(measure)
    if ((measure.Centroid(i,2) > 0) && (measure.Centroid(i,2) < 140) && (measure.Centroid(i,1)>0) && (measure.Centroid(i,1) < 190))
        cluster1(index(1)) = measure.Area(i)
        index(1) = index(1) + 1
    end
    if ((measure.Centroid(i,2) > 0) && (measure.Centroid(i,2) < 140) && (measure.Centroid(i,1)>190) && (measure.Centroid(i,1) < 440))
        cluster2(index(2)) = measure.Area(i)
        index(2) = index(2) + 1
    end
    if ((measure.Centroid(i,2) > 0) && (measure.Centroid(i,2) < 140) && (measure.Centroid(i,1)>440) && (measure.Centroid(i,1) < 690))
        cluster3(index(3)) = measure.Area(i)
        index(3) = index(3) + 1
    end
    if ((measure.Centroid(i,2) > 140) && (measure.Centroid(i,2) < 280) && (measure.Centroid(i,1)>0) && (measure.Centroid(i,1) < 190))
        cluster4(index(4)) = measure.Area(i)
        index(4) = index(4) + 1
    end
    if ((measure.Centroid(i,2) > 140) && (measure.Centroid(i,2) < 280) && (measure.Centroid(i,1)>190) && (measure.Centroid(i,1) < 440))
        cluster5(index(5)) = measure.Area(i)
        index(5) = index(5) + 1
    end
    if ((measure.Centroid(i,2) > 140) && (measure.Centroid(i,2) < 280) && (measure.Centroid(i,1)>440)&& ( measure.Centroid(i,1) < 680))
        cluster6(index(6)) = measure.Area(i)
        index(6) = index(6) + 1
    end
    if( (measure.Centroid(i,2) > 280 )&& (measure.Centroid(i,2) < 390) && (measure.Centroid(i,1)>0) && (measure.Centroid(i,1) < 180))
        cluster7(index(7)) = measure.Area(i)
        index(7) = index(7) + 1
    end
    if ((measure.Centroid(i,2) > 280) && (measure.Centroid(i,2) < 390) && (measure.Centroid(i,1)>180) && (measure.Centroid(i,1) < 440))
        cluster8(index(8)) = measure.Area(i)
        index(8) = index(8) + 1
    end
    if ((measure.Centroid(i,2) > 275) && (measure.Centroid(i,2) < 390) && (measure.Centroid(i,1)>440) && (measure.Centroid(i,1) < 680))
        cluster9(index(9)) = measure.Area(i)
        index(9) = index(9) + 1
    end
    if ((measure.Centroid(i,2) > 380) && (measure.Centroid(i,2) < 500) && (measure.Centroid(i,1)>150) && (measure.Centroid(i,1) < 300))
        cluster10(index(10)) = measure.Area(i)
        index(10) = index(10) + 1
    end
    if ((measure.Centroid(i,2) > 380) && (measure.Centroid(i,2) < 500) && (measure.Centroid(i,1)>300) && (measure.Centroid(i,1) < 680))
        cluster11(index(11)) = measure.Area(i)
        index(11) = index(11) + 1
    end
end
cluster1_size = max(max(cluster1));
cluster2_size = max(max(cluster2));
cluster3_size = max(max(cluster3));
cluster4_size = max(max(cluster4));
cluster5_size = max(max(cluster5));
cluster6_size = max(max(cluster6));
cluster7_size = max(max(cluster7));
cluster8_size = max(max(cluster8));
cluster9_size = max(max(cluster9));    
cluster10_size = max(max(cluster10));
cluster11_size = max(max(cluster11));