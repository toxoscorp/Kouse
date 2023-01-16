// server
/*use tokio::net::TcpListener;
use tokio::io::{AsyncReadExt, AsyncWriteExt};

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let listener = TcpListener::bind("127.0.0.1:8080").await?;

    loop {
        let (mut socket, _) = listener.accept().await?;

        tokio::spawn(async move {
            let mut buf = [0; 1024];

            // In a loop, read data from the socket and write the data back.
            loop {
                let n = match socket.read(&mut buf).await {
                    // socket closed
                    Ok(n) if n == 0 => return,
                    Ok(n) => n,
                    Err(e) => {
                        eprintln!("failed to read from socket; err = {:?}", e);
                        return;
                    }
                };
                // buf[n..n+" hi from server".bytes().len()].copy_from_slice(b" hi from server");
                //
                // //write the buffer to the socket
                // if let Err(e) = socket.write_all(&buf).await {
                //     eprintln!("failed to write to socket; err = {:?}", e);
                //     return;
                // }
            }
        });
    }
}*/

// client
/*// write a simple tokio TCP client that prints the response from the server
// and then exits
// using tokio v1.24.1

use tokio::net::TcpStream;
use tokio::io::{AsyncReadExt, AsyncWriteExt};

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut stream = TcpStream::connect("127.0.0.1:8080").await?;
    stream.write_all(b"hello world").await?;

    let mut buf = [0; 1024];
    stream.read(&mut buf).await?;
    println!("RESPONSE = {}", String::from_utf8_lossy(&buf[..]));
    Ok(())
}*/