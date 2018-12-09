#ifndef __XSC_HTTP2_MIME_RSP_SINK_H__
#define __XSC_HTTP2_MIME_RSP_SINK_H__

__XSC_C_BEGIN_DECL

XSC_INTERNAL_VIEW(
    /**
     * Handle HTTP response codes and finished notifications for mime encoded responses from AVS.
     */
    class MimeResponseStatusHandlerInterface {}
)
/**
 * Handle HTTP response codes and finished notifications for mime encoded responses from AVS.
 */
struct mime_rep_status_hld_op {
// public:
    /**
     * Destructor.
     */
    virtual ~MimeResponseStatusHandlerInterface() = default;

    XSC_INTERNAL_VIEW(
        /**
         * Notification of network activity between this client and AVS.
         * (this is used to detect sustained inactivity requiring the send of a ping).
         */
        virtual void onActivity() = 0;
    )
    /**
     * Notification of network activity between this client and AVS.
     * (this is used to detect sustained inactivity requiring the send of a ping).
     */
    void (*on_activity)(void *data);

    XSC_INTERNAL_VIEW(
        /**
         * Notification that an HTTP response code was returned for the request.
         *
         * @note Calls to this method may block network operations for the associated instance of HTTP2ConnectionInterface,
         * so they should return quickly.
         *
         * @param responseCode The response code received for the request.
         * @return Whether receipt of the response should continue.
         */
        virtual bool onReceiveResponseCode(long responseCode) = 0;
    )
    /**
     * Notification that an HTTP response code was returned for the request.
     *
     * @note Calls to this method may block network operations for the associated instance of HTTP2ConnectionInterface,
     * so they should return quickly.
     *
     * @param responseCode The response code received for the request.
     * @return Whether receipt of the response should continue.
     */
    bool (*on_rcv_rsp_code)(long rsp_code, void *data);

    XSC_INTERNAL_VIEW(
    /**
     * Notification that the request/response cycle has finished and no further notifications will be provided.
     *
     * @note Calls to this method may block network operations for the associated instance of HTTP2ConnectionInterface,
     * so they should return quickly.
     *
     * @param status The status included in the response.
     * @param nonMimeBody The body of the reply (for non HTTPResponseCode::SUCCESS_OK responses)
     */
    virtual void onResponseFinished(
        avsCommon::utils::http2::HTTP2ResponseFinishedStatus status,
        const std::string &nonMimeBody) = 0;
    )
    /**
     * Notification that the request/response cycle has finished and no further notifications will be provided.
     *
     * @note Calls to this method may block network operations for the associated instance of HTTP2ConnectionInterface,
     * so they should return quickly.
     *
     * @param status The status included in the response.
     * @param nonMimeBody The body of the reply (for non HTTPResponseCode::SUCCESS_OK responses)
     */
    void (*on_rsp_finished)(
        avsCommon::utils::http2::HTTP2ResponseFinishedStatus status,
        const char *non_mime_body) = 0;

    /**
     * inheritance class host address
     */
    void *host;
};

__XSC_C_END_DECL

#endif /* end of include guard: __XSC_HTTP2_MIME_RSP_SINK_H__ */
/* vim: set ts=8 sw=8 noexpandtab: */
