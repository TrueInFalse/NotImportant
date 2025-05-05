#include <doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <title>时钟及新年倒计时</title>
  <style type="text/css">
 #bp{
   background-image:url("钟.jpg");
   width:500px;
   height:500px;
   position:relative;
 }
 #bp>div.hour{
   width:16px;
   height:100px;
   background-color:blue;
   position:absolute;
   left:242px;
   bottom:250px;
   transform-origin:bottom;
 }
 #bp>div.min{
   width:10px;
   height:150px;
   background-color:green;
   position:absolute;
   left:245px;
   bottom:250px;
   transform-origin:bottom;
 }
  #bp>div.sed{
   width:6px;
   height:200px;
   background-color:red;
   position:absolute;
   left:247px;
   bottom:250px;
   transform-origin:bottom;
 }
  </style>
 </head>
 <body>
   <div id="today">
 2019年12月4日 10:01:02
   </div>
   <div id="bp" class="">
 <div class="hour"></div>
 <div class="min"></div>
 <div class="sed"></div>
   </div>
   <div id="djs">
 距离2020年新年还有80天10小时20分钟30秒
   </div>
    <script>
    function nowtime(){
  //定义变量，赋值新建一个时间对象；
     var date = new Date();//获取当前时间
  //获取当前时间的年份；2019
  var year = date.getFullYear();
  //获取当前时间的月份；11
  var month = date.getMonth()+1;
  //获取当前时间的日期；4
  var day = date.getDate();
  //获取当前时间的小时数；10
  var hour = date.getHours();
  //获取当前时间的分钟数；
  var min = date.getMinutes();
  //获取当前时间的秒数；
  var second = date.getSeconds();
  //计算时针旋转的角度
  var hour_deg = (hour+min/60)*30;
  
  //让时针旋转
  document.querySelector("#bp>div.hour").style = "transform:rotate("+hour_deg+"deg);";
  if (hour<10){
   hour = "0"+hour;
  }
  //计算分针旋转角度
  var min_deg = (min+second/60)*6;
  //让分针旋转
  document.querySelector("#bp>div.min").style = "transform:rotate("+min_deg+"deg)";
  if (min<10){
   min = "0"+min;
  }
  
  //计算秒针旋转的角度
  var sed_deg = second*6;
  //让秒针旋转
  document.querySelector("#bp>div.sed").style = "transform:rotate("+sed_deg+"deg);";
  if (second<10){
   second = "0" + second;
  }
  //拼接字符串成显示内容；
  var html = year+"年"+month+"月"+day+"日 "+hour+":"+min+":"+second;
  //改变元素显示在页面的内容
  document.getElementById("today").innerHTML = html;
  //倒计时
  var newyear = new Date(2020,0,24,0,0,0);//获取2020新年时间
  var djs = newyear - date//获取倒计时的毫秒数
  //将毫秒数转化成天数时分秒
  //获取倒计时天数
  var djs_day = parseInt(djs/(1000*60*60*24));
  //获取倒计时小时数
  var djs_hour = parseInt(djs/(1000*60*60)%24);
  //获取倒计时分钟数
  var djs_min = parseInt(djs/(1000*60)%60);
  //获取倒计时秒数
  var djs_sed = parseInt(djs/1000%60);
  //将获取的倒计时时间显示在网页上
   var djs_html = "距离2020年新年还有"+djs_day+"天"+djs_hour+"小时"+djs_min+"分钟"+djs_sed+"秒";
  document.getElementById("djs").innerHTML = djs_html;
  console.log(djs_sed);
 }
 nowtime();
    setInterval(nowtime,1000);
  </script>
 </body>
</html>
