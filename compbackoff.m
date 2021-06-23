
 

close all;

yax_linear = [17 24 32 52 43 57 67 98 87 127 158 168 212 171 249 276 293 306 309 378 338 437 432 462 517 531 558 572 582 630 622 693 718 764 808 775 838 899 913 923 983 1036 1051 1111 1054 1107 1186 1193 1195 1299 1402 1409 1429 1408 1427 1525 1525 1566 1588 1753
];
%new_yax_linear = yax_linear + 6000;
yax_log = [14 18 19 36 28 30 53 79 87 119 128 113 145 152 142 185 204 223 233 256 295 336 373 347 359 386 407 426 502 454 525 524 565 615 619 616 677 692 763 731 809 834 852 877 890 902 913 982 988 1066 1106 1081 1156 1123 1173 1214 1264 1305 1280 1395];
%new_yax_log = yax_log + 6000;
yax_expo = [11 11 28 17 12 16 32 68 56 66 56 71 80 69 112 128 145 148 195 134 203 222 197 213 241 286 296 280 376 323 371 376 411 461 435 504 492 524 547 515 570 668 611 601 665 705 746 726 765 735 791 866 840 936 891 900 1047 1017 1087 1011
];
%new_yax_expo = yax_expo + 6000;

xax = 100:100:6000;

% plot(xax,yax);
%% 
figure;
scatter(xax,yax_linear);
xlabel('Number of Users');
ylabel('Latency');
title('Linear Backoff Protocol');
legend('Linear Backoff Protocol');


%% 
figure;
scatter(xax,yax_log);
xlabel('Number of Users');
ylabel('Latency');
title('Logarithmic Backoff Protocol');
legend('Logarithmic Backoff Protocol');

%% 
figure;
scatter(xax,yax_expo);
xlabel('Number of Users');
ylabel('Latency');
title('Binary Exponential Backoff Protocol');
legend('Binary Exponential Backoff Protocol');

%% 

figure;
scatter(xax,yax_linear);
%scatter(xax,new_yax_linear);
hold on;
scatter (xax,yax_log);
%scatter(xax,new_yax_log);
hold on;
%scatter(xax,new_yax_expo);
scatter (xax, yax_expo);
xlabel('Number of Users');
ylabel('Latency');
title('Latency Comparision of Protocols');
legend('Linear Backoff Protocol','Logarithmic Backoff Protocol','Binary Exponential Backoff Protocol');

