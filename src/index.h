//WebページのHTMLです

#ifndef INDEX_H
#define INDEX_H

static const char html[] = R"(

<!DOCTYPE html>
<html>
  <head>
    <meta charset='utf-8' />
      <meta http-equiv='X-UA-Compatible' content='IE=edge' />
      <meta name='viewport' content='width=device-width,initial-scale=1' />
      <title>Captive_Portal_Monitor</title>
  </head>
  <style>
    body {
      font-family: monospace;
      background-color: white;
      text-align: center;
    }
    h1 {
      margin: 30px 0;
      font-size: 20px;
    }
    p {
      margin: 1em;
      font-size: 15px;
      text-align: left;
      word-wrap: break-word;
      white-space: pre-wrap; /* 改行コードを有効化 */
    }
    .monitor {
      margin: 10px auto;
      max-width: 550px;
      border: solid 1px black;
      border-radius: 10px;
      background-color: rgba(255,255,255,0.5);
    }
  </style>
  <body>
    <h1>Captive_Portal_Monitor</h1>
    <div class='monitor'>
      <p id='monitor'></p>
    </div>
  </body>
  <script type='text/javascript'>
    function updateData() {
      const getData = fetch('/get/data')
        .then((response) => response.text())
        .then((data) => {
          console.log(data);
          const monitor = document.getElementById('monitor');
          monitor.textContent = data;
        })
        .then(() => {
          setTimeout(() => {
            updateData();
          }, 500); // Polling Interval
        })
        .catch(() => {
          console.error('Rejected getData');
          setTimeout(() => {
            updateData();
          }, 1000);
        });
    }

    function dummy() {
      setTimeout(() => {
        const now = new Date();
        console.log(now);
        const monitor = document.getElementById('monitor');
        monitor.textContent = '現在の時刻を表示しています\n\n' + now;
        dummy();
      }, 100);
    }

    setTimeout(updateData,100); // Function Start Timing
  </script>
</html>

)";

#endif // INDEX_H
