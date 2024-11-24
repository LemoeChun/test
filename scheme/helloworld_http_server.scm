;;; Hello HTTP server
(use-modules (web server))

(define (my-handler request request-body)
    (values '((content-type . (text/plain)))
                      "Hello World!"))

(run-server my-handler)
